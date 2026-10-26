#include "mywidget.h"
#include "ui_mywidget.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QFileDialog>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    // 1. 設定表格總共有 4 個欄位[cite: 12]
    ui->tableWidget->setColumnCount(4);

    // 2. 建立欄位標頭名稱清單[cite: 14, 15]
    QStringList ColTotle;
    ColTotle << QStringLiteral("學號")
             << QStringLiteral("班級")
             << QStringLiteral("姓名")
             << QStringLiteral("電話");

    // 3. 將標頭設定至 tableWidget 中[cite: 16]
    ui->tableWidget->setHorizontalHeaderLabels(ColTotle);
}
void MyWidget::on_pushButton_3_clicked()
{
    QTableWidgetItem *inputRow1 = new QTableWidgetItem(QString(ui->lineEdit->text()));
    QTableWidgetItem *inputRow2 = new QTableWidgetItem(QString(ui->lineEdit_2->text()));
    QTableWidgetItem *inputRow3 = new QTableWidgetItem(QString(ui->lineEdit_3->text()));
    QTableWidgetItem *inputRow4 = new QTableWidgetItem(QString(ui->lineEdit_4->text()));

    // 在 tableWidget 尾端插入新的一列[cite: 22]
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    // 將資料填入對應的儲存格中[cite: 24]
    ui->tableWidget->setItem(row, 0, inputRow1);
    ui->tableWidget->setItem(row, 1, inputRow2);
    ui->tableWidget->setItem(row, 2, inputRow3);
    ui->tableWidget->setItem(row, 3, inputRow4);

    // 清空輸入框[cite: 30]
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
}
QString mFilename = "C:/test/myfile.txt"; // 存檔路徑[cite: 26, 27]

void Write(QString Filename, QString str) {
    QFile mFile(Filename);
    if (!mFile.open(QFile::WriteOnly | QFile::Text)) {
        qDebug() << "could not open file for write";
        return;
    }
    QTextStream out(&mFile);
    out << str;
    mFile.flush();
    mFile.close();
}


void MyWidget::on_pushButton_2_clicked()
{
    QString saveFile = ""; // 存檔內容

    // 走訪表格中所有的列與欄
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        for (int j = 0; j < ui->tableWidget->columnCount(); j++) {
            // 檢查該儲存格是否有內容，避免發生崩潰
            if (ui->tableWidget->item(i, j) != nullptr) {
                saveFile += ui->tableWidget->item(i, j)->text() + ",";
            } else {
                saveFile += ","; // 若該格為空則補逗號
            }
        }
        saveFile += "\n"; // 換行
    }

    // 呼叫 Write 方法將字串寫入檔案
    Write(mFilename, saveFile);
}


void MyWidget::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        QStringLiteral("選擇匯入通訊錄"),
        "",
        QStringLiteral("CSV 檔案 (*.csv);;文字檔 (*.txt);;所有檔案 (*.*)")
        );

    if (fileName.isEmpty()) {
        return; // 使用者若取消則中斷
    }

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        return;
    }

    QTextStream in(&file);

    // 逐行讀取檔案內容
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.trimmed().isEmpty()) {
            continue;
        }

        // 依據逗號切割字串
        QStringList fields = line.split(",");

        // 在表格中新增一列
        int currentRow = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(currentRow);

        // 將切割好的資料填入對應欄位
        for (int i = 0; i < fields.size() && i < 4; ++i) {
            QTableWidgetItem *item = new QTableWidgetItem(fields.at(i));
            ui->tableWidget->setItem(currentRow, i, item);
        }
    }

    file.close();
}
MyWidget::~MyWidget()
{
    delete ui;
}


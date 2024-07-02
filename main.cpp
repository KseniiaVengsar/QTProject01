#include <QApplication>
#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtNetwork/QNetworkAccessManager>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //главное окно
    QMainWindow mainWindow;
    mainWindow.show();

    //класс БД
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if (!db.open()) {
        qDebug() << "Не удалось открыть базу данных!";
    } else {
        qDebug() << "База данных успешно открыта.";
    }

    //класс для работы с сетью
    QNetworkAccessManager networkManager;
    qDebug() << "Экземпляр QNetworkAccessManager создан.";

    return app.exec();
}

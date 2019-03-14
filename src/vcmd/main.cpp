#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>

#define DBHOST "tcp://127.0.0.1:3306"
#define USER "vcmuser"
#define PASSWORD "vcmuser"
#define DATABASE "vcongressman"

int main()
{
    sql::Driver *driver;
    sql::Connection *connection;
    sql::Statement *statement;

    //Realizamos la conexión al servidor con vcmuser
    driver = get_driver_instance();
    connection = driver->connect(DBHOST, USER, PASSWORD);

    //Seleccionamos la base de datos
    connection->setSchema(DATABASE);

    //DELETE de la reserva de plaza en ListaVisitantes si no se ha activado en 24h el visitante mediante el enlace enviado a la dirección de correo electrónico registrada.
    statement = connection->createStatement();
    try {
      statement->executeQuery("DELETE FROM ListaVisitantes WHERE (IDEvento, IDVisitante) IN (SELECT IDEvento,IDVisitante FROM ValidaReserva WHERE Fin < NOW());");
    } catch (sql::SQLException &e) {}
    //DELETE del Visitante si no tiene plazas activas reservadas en ningún Evento.
    statement = connection->createStatement();
    try {
      statement->executeQuery("DELETE FROM Visitante WHERE IDVisitante NOT IN (SELECT IDVisitante FROM ListaVisitantes);");
    } catch (sql::SQLException &e) {}
    //DELETE del MD5 caducado que posibilitaba la activación del Visitante en el Evento en ListaVisitantes.
    statement = connection->createStatement();
    try {
      statement->executeQuery("DELETE FROM ValidaReserva WHERE Fin < NOW();");
    } catch (sql::SQLException &e) {}
    //Borramos los objectos usados
    delete statement;
    delete connection;
    return 0;
}

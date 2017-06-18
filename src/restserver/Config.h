#ifndef CONFIG_H
#define CONFIG_H


#define HTTP_OK 200
#define HTTP_CREATED 201
#define HTTP_BAD_REQUEST 400
#define HTTP_FORBIDDEN 403
#define HTTP_UNPROCESSABLE 422
#define HTTP_NOT_FOUND 404
#define HTTP_GET "GET"
#define HTTP_POST "POST"
#define HTTP_PUT "PUT"
#define HTTP_DELETE "DELETE"
#define TRACK_ID_KEY "track_id"
#define USERNAME_KEY "userName"
#define PASSWORD_KEY "password"
#define MONGO_HOST "mongodb://admin:admin@musicio-shard-00-00-7k5wq.mongodb.net:27017,musicio-shard-00-01-7k5wq.mongodb.net:27017,musicio-shard-00-02-7k5wq.mongodb.net:27017/musiciodb?ssl=true&replicaSet=musicio-shard-0&authSource=admin"
#define PORT 9000
#define SHARED_SERVER_TOKEN "http://musicio.herokuapp.com/token"





#endif // CONFIG_H

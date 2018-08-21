#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include "DHT.h"

// Initialize Wifi connection to the router
#define WIFI_SSID "Winter is Coming"
#define WIFI_PASSWORD "985090300"
#define BOTtoken "600697851:AAHL4mGw8OdXNPxCPYVmi967awRV4V02rTU"  // Seu token do telegram


#define PIN_D0 D0
#define PIN_D1 D1
#define PIN_D2 D2
#define PIN_D3 D3
#define PIN_D4 D4
#define PIN_D6 D6
#define PIN_D7 D7
#define PIN_D8 D8


#define DHT_PIN D5
#define DHTTYPE DHT11

#define BOT_SCAN_MESSAGE_INTERVAL 1000 //Intervalo para obter novas mensagens
long lastTimeScan;  // Ultima vez que buscou mensagem
bool pinoD0 = false; // Estado do pino d0
bool pinoD1 = false; // Estado do pino d1
bool pinoD2 = true; // Estado do pino d2
bool pinoD3 = false; // Estado do pino d3
bool pinoD4 = false; // Estado do pino d4
bool pinoD6 = false; // Estado do pino d6
bool pinoD7 = false; // Estado do pino d7
bool pinoD8 = false; // Estado do pino d8



WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);
DHT dht(DHT_PIN, DHTTYPE);

// Trata as novas mensagens que chegaram
void handleNewMessages(int numNewMessages) {
  

  for (int i=0; i<numNewMessages; i++) {
    String chat_id = String(bot.messages[i].chat_id);
    String text = bot.messages[i].text;

    // Pessoa que está enviando a mensagem
    String from_name = bot.messages[i].from_name;    
    if (from_name == "") from_name = "Convidado";

    // Tratamento para cada tipo de comando a seguir.

    /*if (text == "/pinoon") {
      digitalWrite(pino_PIN, HIGH);   // turn the pino on (HIGH is the voltage level)
      pinoStatus = true;
      bot.sendMessage(chat_id, "pino está ligado", "");
    }*/
    
    if (text == "/d0on") {
      digitalWrite(PIN_D0, HIGH);   // turn the pino on (HIGH is the voltage level)
      pinoD0 = true;
      bot.sendMessage(chat_id, "D0 está ligado", "");
    }
    if (text == "/d1on") {
      digitalWrite(PIN_D1, HIGH);   // turn the pino on (HIGH is the voltage level)
      pinoD1 = true;
      bot.sendMessage(chat_id, "D1 está ligado", "");
    }
   /* if (text == "/d2on") {
      digitalWrite(PIN_D2, HIGH);   // turn the pino on (HIGH is the voltage level)
      pinoD2 = true;
      bot.sendMessage(chat_id, "D2 está ligado", "");
    }*/
    
     if (text == "/d3on") {
      digitalWrite(PIN_D3, HIGH);   // turn the pino on (HIGH is the voltage level)
      pinoD3 = true;
      bot.sendMessage(chat_id, "D3 está ligado", "");
     }

     if (text == "/d4on") {
      digitalWrite(PIN_D4, HIGH);   // turn the pino on (HIGH is the voltage level)
      pinoD4 = true;
      bot.sendMessage(chat_id, "D3 está ligado", "");
     }


    if (text == "/d6on") {
      digitalWrite(PIN_D6, HIGH);
      pinoD6 = true;
      bot.sendMessage(chat_id, "D6 está ligado", "");
    }

    if (text == "/d7on") {
      digitalWrite(PIN_D7, HIGH);   // turn the pino on (HIGH is the voltage level)
      pinoD7 = true;
      bot.sendMessage(chat_id, "D7 está ligado", "");
    }

    if (text == "/d8on") {
      digitalWrite(PIN_D8, HIGH);
      pinoD8 = true;
      bot.sendMessage(chat_id, "D8 está ligado", "");
    }

    //Desliga o pino correnspondente 
   
    if (text == "/d0off") {
      pinoD0 = false;
      digitalWrite(PIN_D0, LOW);    // turn the pino off (LOW is the voltage level)
      bot.sendMessage(chat_id, "D0 está desligado", "");
    }
    
    if (text == "/d1off") {
      pinoD1 = false;
      digitalWrite(PIN_D1, LOW);    // turn the pino off (LOW is the voltage level)
      bot.sendMessage(chat_id, "D1 está desligado", "");
    }

     /*if (text == "/d2off") {
      pinoD2 = false;
      digitalWrite(PIN_D2, LOW);    // turn the pino off (LOW is the voltage level)
      bot.sendMessage(chat_id, "pino está desligado", "");
    }*/
  
    if (text == "/d3off") {
      pinoD3 = false;
      digitalWrite(PIN_D3, LOW);    // turn the pino off (LOW is the voltage level)
      bot.sendMessage(chat_id, "D3 está desligado", "");
    }
    
    if (text == "/d4off") {
      pinoD4 = false;
      digitalWrite(PIN_D4, LOW);    // turn the pino off (LOW is the voltage level)
      bot.sendMessage(chat_id, "D4 está desligado", "");
    }

    if (text == "/d6off") {
      pinoD6 = false;
      digitalWrite(PIN_D6, LOW);
      bot.sendMessage(chat_id, "D6 está desligado", "");
    }
    
    if (text == "/d7off") {
      pinoD7 = false;
      digitalWrite(PIN_D7, LOW);    // turn the pino off (LOW is the voltage level)
      bot.sendMessage(chat_id, "D7 está desligado", "");
    }
    
    if (text == "/d8off") {
      pinoD8 = false;
      digitalWrite(PIN_D8, LOW);
      bot.sendMessage(chat_id, "D8 está desligado", "");
    }

    //Status do Estados dos Pinos
    if (text == "/status") {
      String message = "pino D0 está ";
      if(pinoD0){
        message += "ligado";
      }else{
        message += "desligado";
      }
      message += ". \n";
           
      message += "pino D1 está ";
      if(pinoD1){
        message += "ligado";
      }else{
         message += "desligado";
      }
      message += ". \n";

     /* message += "pino D2 está ";
      if(pinoD2){
        message += "ligado";
      }else{
         message += "desligado";
      }
      message += ". \n";
      */
      message += "pino D3 está ";
      if(pinoD3){
        message += "ligado";
      }else{
         message += "desligado";
      }
      message += ". \n";
      message += "pino D4 está ";
      if(pinoD4){
        message += "ligado";
      }else{
         message += "desligado";
      }
      message += ". \n";
      
      message += "pino D6 está ";
      if(pinoD6){
        message += "ligado";
      }else{
         message += "desligado";
      }
      message += ". \n";

      message += "pino D7 está ";
      if(pinoD7){
        message += "ligado";
      }else{
         message += "desligado";
      }
      message += ". \n";
      
      message += "pino D8 está ";
      if(pinoD8){
        message += "ligado";
      }else{
         message += "desligado";
      }
      message += ". \n";
      
      bot.sendMessage(chat_id, message, "Markdown");      
    }

    if( text == "/env") {
      //Pega os dados de Umidade e Temperatura
      float humidity = dht.readHumidity();
      float temperature = dht.readTemperature();

      
      String message = "A temperatura é de " + String(temperature, 2) + " graus celsius.\n";
      message += "A umidade relativa do ar é de " + String(humidity, 2)+ "%.\n\n";      
      bot.sendMessage(chat_id, message, "");
    }

    // Cria teclado com as opções de comando
    if (text == "/options") {
      String keyboardJson = "[[\"/d0on\", \"/d0off\"],[\"/d1on\", \"/d1off\"],[\"/d3on\", \"/d3off\"],[\"/d4on\", \"/d4off\"],[\"/d6on\", \"/d6off\"],[\"/d7on\", \"/d7off\"],[\"/d8on\", \"/d8off\"],[\"/env\",\"/status\"],[\"/options\"]]";
      bot.sendMessageWithReplyKeyboard(chat_id, "Escolha uma das opções", "", keyboardJson, true);
    }

    
    // Comando de inicio de conversa no telegram
    if (text == "/start") {
      String welcome = from_name + ", Bem-vindo.\n";
      welcome += "Para interagir, use um dos comandos a seguir.\n\n";
      
      welcome += "/d0on : para ligar o pino D0 \n";
      welcome += "/d1on : para ligar o pino D1 \n";
      welcome += "/d2on : para ligar o pino D2 \n";
      welcome += "/d3on : para ligar o pino D3 \n";
      welcome += "/d4on : para ligar o pino D4 \n";
      welcome += "/d6on : para ligar o pino D6 \n";
      welcome += "/d7on : para ligar o pino D7 \n";
      welcome += "/d8on : para ligar o pino D8 \n";
     
      
      welcome += "/d0off : para desligar o pino D0 \n";
      welcome += "/d1off : para desligar o pino D1 \n";
      welcome += "/d2off : para desligar o pino D2 \n";
      welcome += "/d3off : para desligar o pino D3 \n";
      welcome += "/d4off : para desligar o pino D4 \n";
      welcome += "/d6off : para desligar o pino D6 \n";
      welcome += "/d7off : para desligar o pino D7 \n";
      welcome += "/d8off : para desligar o pino D8 \n";

      
      welcome += "/env : saber a temperatura e umidade do ambiente \n";
      welcome += "/status : para saber o status do Sensor e dos Pinos \n";
      bot.sendMessage(chat_id, welcome, "Markdown");
    }
  }
}


void setupWifi(){  

  // attempt to connect to Wifi network:
  // Serial.print("Connecting Wifi: ");
  // Serial.println(ssid);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    // Serial.print(".");
    delay(500);
  }

  // Serial.println("");
  // Serial.println("WiFi connected");
  // Serial.print("IP address: ");
  // Serial.println(WiFi.localIP());
}

void setupPins(){
  pinMode(PIN_D0, OUTPUT); 
  pinMode(PIN_D1, OUTPUT); 
 // pinMode(PIN_D2, OUTPUT); 
  pinMode(PIN_D3, OUTPUT);
  pinMode(PIN_D4, OUTPUT);
  pinMode(PIN_D6, OUTPUT); 
  pinMode(PIN_D7, OUTPUT);
  pinMode(PIN_D8, OUTPUT);
  delay(10);
  digitalWrite(PIN_D0, LOW); 
 // digitalWrite(PIN_D1, LOW);
  digitalWrite(PIN_D2, LOW);
  digitalWrite(PIN_D3, LOW);
  digitalWrite(PIN_D4, LOW);
  digitalWrite(PIN_D6, LOW);
  digitalWrite(PIN_D7, LOW);
  digitalWrite(PIN_D8, LOW);

  dht.begin();
}

void setup() {
  // Serial.begin(115200);

  setupWifi();
  setupPins();

  lastTimeScan = millis();
}

void loop() {
  if (millis() > lastTimeScan + BOT_SCAN_MESSAGE_INTERVAL)  {
    // Serial.print("Checking messages - ");
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);  
    // Serial.println(numNewMessages);
    while(numNewMessages) {
      // Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }

    lastTimeScan = millis();
  }
  yield();
  delay(10);
}

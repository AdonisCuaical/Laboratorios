#include<LiquidCrystal.h>
LiquidCrystal lcd(A5, A4, A3, A2, A1, A0);
String n;
String m;
String m1;
const String r = "  Bienvenido  ";
int tam;
String nom[100];
#define COLS 16 // Columnas del LCD
#define ROWS 2 // Filas del LCD
#define VELOCIDAD 100 // Velocidad a la que se mueve el texto
const int btn = 2;
int cont = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(COLS, ROWS);
  lcd.setCursor(0, 0);
  lcd.print("_____________________ ");
  lcd.setCursor(0, 1);
  pinMode(btn, INPUT);
}

void loop() {

  if (digitalRead(btn) == LOW) {
    if (Serial.available() > 0) {
      n = Serial.readString();
      nom[cont] = n;
      cont++;
      if (n == "ca900813") {
        m1 = "Carlos Arias ";
      } else if (n == "aj881112") {
        m1 = "Andres Juarez";
      } else if (n == "ja890109") {
        m1 = "Javier Andrada ";
      } else if (n == "ac101999") {
        m1 = "Cuaical Adonis";
      } else {
        m1 = "Usuario no registrado.......!";
      }
      if (m1 == "Usuario no registrado.......!") {
        m = m1;
      } else {
        m = r + m1;
      }
      Serial.println(String("  ")); 
      Serial.println(m1);

      int tam = m.length();
      for (int i = 1; i < tam + 2 ; i++)
      {
        digitalRead(btn);
        String texto = m.substring(i - 1);

        // Limpiamos pantalla
        lcd.clear();

        //Situamos el cursor
        lcd.setCursor(0, 1);

        // Escribimos el texto
        lcd.print(texto);

        // Esperamos
        delay(VELOCIDAD);
      }
    }
    if (digitalRead(btn) == HIGH) {
      Serial.println(String("Ingresos: "));
      for (int j = 0; j < cont; j++) {
        if (nom[j] == "ca900813") {
          m1 = "Carlos Arias ";
        } else if (nom[j] == "aj881112") {
          m1 = "Andres Juarez";
        } else if (nom[j] == "ja890109") {
          m1 = "Javier Andrada ";
        } else if (nom[j] == "ac101999") {
          m1 = "Cuaical Adonis";
        } else {
          m1 = "Usuario no registrado.......!";
        }
        
        Serial.println(m1);
      }
      Serial.println("_______________"); 
    }
  }
}

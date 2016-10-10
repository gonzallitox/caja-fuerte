

#include <Keypad.h> //llama a la librería Keypad.h
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f, 16, 2);

int conta = 0;
char contrasena[] = "37D2BC456A8D*56"; //aquí escribimos la contraseña de 4 dígitos
char codigo[15];            //Cadena donde se guardaran los caracteres de las teclas presionadas
int cont = 0;        //variable que se incrementara al presionar las teclas
int caracteres = 0;

const byte ROWS = 4; //Numero de filas del teclado que se esta usando
const byte COLS = 4; //Numero de columnas del teclado que se esta usando

char hexaKeys[ROWS][COLS] =  //Aquí pondremos la disposición de los caracteres tal cual están en nuestro teclado
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //Seleccionamos los pines en el arduino donde iran conectadas las filas
byte colPins[COLS] = {5, 4, 3, 2}; //Seleccionamos los pines en el arduino donde iran conectadas las filas

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); //inicializa el teclado

void setup()
{
  //Iniciamos el fondo retroiluminado
  lcd.backlight();
  //Iniciamos la pantalla
  lcd.init();
  lcd.setCursor(0, 0);
  lcd.print("L");
  lcd.print("O");
  lcd.print("C");
  lcd.print("K");
  lcd.print("P");
  lcd.print("I");
  lcd.print("C");
  lcd.print("K");
  lcd.print("A");
  lcd.print("R");
  lcd.print("!");
  delay(5000);
  lcd.setCursor(0, 1);
  lcd.print("T");
  lcd.print("I");
  lcd.print("E");
  lcd.print("N");
  lcd.print("E");
  lcd.print(" ");
  lcd.print("3");
  lcd.print(" ");
  lcd.print("I");
  lcd.print("N");
  lcd.print("T");
  lcd.print("E");
  lcd.print("N");
  lcd.print("T");
  lcd.print("O");
  lcd.print("S");


  delay(5000);
  lcd.clear();//Limpiamos la LCD
  lcd.setCursor(0, 0);
  lcd.print("I");
  lcd.print("N");
  lcd.print("G");
  lcd.print("R");
  lcd.print("E");
  lcd.print("S");
  lcd.print("E");
  lcd.print(" ");
  lcd.print("L");
  lcd.print("A");
  lcd.print(" ");
  lcd.print("C");
  lcd.print("L");
  lcd.print("A");
  lcd.print("V");
  lcd.print("E");
  lcd.print(":");



}

void loop()
{



  char customKey = customKeypad.getKey(); //se guarda en la variable customKey el caracter de la tecla presionada
  if (customKey != NO_KEY)         //se evalúa si se presionó una tecla
  {
    

    codigo[cont] = customKey;        //se guarda caracter por caracter en el arreglo codigo[]
    lcd.setCursor(caracteres, 1);
    lcd.print(codigo[cont]);    //se imprime en el puerto serie la tecla presionada
     tone(10, 500, 50);
    cont = cont + 1;  //incrementamos la variable cont
 
    caracteres++;
    if (cont == 15)       //si ya fueron presionadas 4 teclas se evalúa si la contraseña es correcta
    {
      
      caracteres = 0;
      if (codigo[0] == contrasena[0] && codigo[1] == contrasena[1] && codigo[2] == contrasena[2] && codigo[3] == contrasena[3] && codigo[4] == contrasena[4] && codigo[5] == contrasena[5] && codigo[6] == contrasena[6] && codigo[7] == contrasena[7] && codigo[8] == contrasena[8] && codigo[9] == contrasena[9] && codigo[10] == contrasena[10] && codigo[11] == contrasena[11] && codigo[12] == contrasena[12] && codigo[13] == contrasena[13] && codigo[14] == contrasena[14])
      {
        lcd.clear();//Limpiamos la LCD
        lcd.print("P");
        lcd.print("R");
        lcd.print("O");
        lcd.print("C");
        lcd.print("E");
        lcd.print("S");
        lcd.print("A");
        lcd.print("N");
        lcd.print("D");
        lcd.print("O");
        lcd.print(".");
        lcd.print(".");
        lcd.print(".");
        delay(3000);
        lcd.clear();//Limpiamos la LCD
        tone(10,600,800);  
        lcd.setCursor(0, 0);
        lcd.print("C");
        lcd.print("L");
        lcd.print("A");
        lcd.print("V");
        lcd.print("E");
        lcd.print(" ");
        lcd.print("C");
        lcd.print("O");
        lcd.print("R");
        lcd.print("R");
        lcd.print("E");
        lcd.print("C");
        lcd.print("T");
        lcd.print("A");


        lcd.setCursor(0, 1);
        lcd.print("C");
        lcd.print("O");
        lcd.print("D");
        lcd.print("I");
        lcd.print("G");
        lcd.print("O");
        delay(3000);
        conta=conta-conta ;


      }
      else
      {
        lcd.clear();//Limpiamos la LCD
        lcd.print("P");
        lcd.print("R");
        lcd.print("O");
        lcd.print("C");
        lcd.print("E");
        lcd.print("S");
        lcd.print("A");
        lcd.print("N");
        lcd.print("D");
        lcd.print("O");
        lcd.print(".");
        lcd.print(".");
        lcd.print(".");
        delay(3000);


        lcd.clear();//Limpiamos la LCD
        lcd.setCursor(0, 0);
         tone(10,4000,300);
        delay(100);
        tone(10,100,300);
       
        lcd.print("C");
        lcd.print("L");
        lcd.print("A");
        lcd.print("V");
        lcd.print("E");
        lcd.print(" ");
        lcd.print("I");
        lcd.print("N");
        lcd.print("C");
        lcd.print("O");
        lcd.print("R");
        lcd.print("R");
        lcd.print("E");
        lcd.print("C");
        lcd.print("T");
        lcd.print("A");
        
        delay(3000);
        conta = conta + 1;
        lcd.clear();//Limpiamos la LCD
        lcd.setCursor(0, 0);
        lcd.print("I");
        lcd.print("N");
        lcd.print("G");
        lcd.print("R");
        lcd.print("E");
        lcd.print("S");
        lcd.print("E");
        lcd.print(" ");
        lcd.print("L");
        lcd.print("A");
        lcd.print(" ");
        lcd.print("C");
        lcd.print("L");
        lcd.print("A");
        lcd.print("V");
        lcd.print("E");
        lcd.print(":");
      }
      if (conta == 3)
      {
        tone(10,1000,300000);
        lcd.clear();//Limpiamos la LCD
        lcd.setCursor(0, 0);
        lcd.print("L");
        lcd.print("I");
        lcd.print("M");
        lcd.print("I");
        lcd.print("T");
        lcd.print("E");
        lcd.print(" ");
        lcd.print("S");
        lcd.print("U");
        lcd.print("P");
        lcd.print("E");
        lcd.print("R");
        lcd.print("A");
        lcd.print("D");
        lcd.print("O");
        lcd.setCursor(0, 1);
        lcd.print("E");
        lcd.print("S");
        lcd.print("P");
        lcd.print("E");
        lcd.print("R");
        lcd.print("E");
        lcd.print(" ");
        lcd.print("5");
        lcd.print(" ");
        lcd.print("M");
        lcd.print("I");
        lcd.print("N");
        lcd.print(".");
        delay(300000);

        conta = 0;


      }


      cont = 0; //resetear a 0 la variable cont
      lcd.clear();//Limpiamos la LCD
      lcd.setCursor(0, 0);
      lcd.print("L");
      lcd.print("O");
      lcd.print("C");
      lcd.print("K");
      lcd.print("P");
      lcd.print("I");
      lcd.print("C");
      lcd.print("K");
      lcd.print("A");
      lcd.print("R");
      lcd.print("!");
      delay(5000);
      lcd.clear();//Limpiamos la LCD
      lcd.setCursor(0, 0);
      lcd.print("R");
      lcd.print("E");
      lcd.print("C");
      lcd.print("U");
      lcd.print("E"); 
      lcd.print("R");
      lcd.print("D");
      lcd.print("E");
      lcd.print(" ");
      lcd.print("Q");
      lcd.print("U");
      lcd.print("E");
      lcd.print(":");
      lcd.setCursor(0, 1);
      lcd.print("T");
      lcd.print("I");
      lcd.print("E");
      lcd.print("N");
      lcd.print("E");
      lcd.print(" ");
      lcd.print("3");
      lcd.print(" ");
      lcd.print("I");
      lcd.print("N");
      lcd.print("T");
      lcd.print("E");
      lcd.print("N");
      lcd.print("T");
      lcd.print("O");
      lcd.print("S");
      delay(5000);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("I");
      lcd.print("N");
      lcd.print("G");
      lcd.print("R");
      lcd.print("E");
      lcd.print("S");
      lcd.print("E");
      lcd.print(" ");
      lcd.print("L");
      lcd.print("A");
      lcd.print(" ");
      lcd.print("C");
      lcd.print("L");
      lcd.print("A");
      lcd.print("V");
      lcd.print("E");
      lcd.print(":");

    }



  }

}

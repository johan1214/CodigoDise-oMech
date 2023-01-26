const int Trigger1 = 13;
const int Echo1 = 12;
const int Trigger2 = 7;
const int Echo2 = 6;
const int Trigger3 = 3;
const int Echo3 = 2;
const int Motores = 10;
const int Camara = 14;
const int Buzzer = 4;
int EstadoBoton;
int EstadoBoton1;
int EstadoBoton2;

bool estado = false;
bool estado1 = false;
bool estado2 = false;
int but = 8;
int but1 = 9;
int but2 = 5;

void setup() {
  Serial.begin(9600);
  pinMode(Trigger1, OUTPUT);
  pinMode(Echo1, INPUT);
  digitalWrite(Trigger1, LOW);
  pinMode(Trigger2, OUTPUT);
  pinMode(Echo2, INPUT);
  digitalWrite(Trigger2, LOW);
  pinMode(Trigger3, OUTPUT);
  pinMode(Echo3, INPUT);
  pinMode(Camara, INPUT);
  pinMode(Motores, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(but, INPUT);
  pinMode(but1, INPUT);
  pinMode(but2, INPUT);



  digitalWrite(Trigger3, LOW);
}


void loop() {
  bool b;
  long d1 = obtenerDistancia(Trigger1, Echo1);
  long d2 = obtenerDistancia(Trigger2, Echo2);
  long d3 = obtenerDistancia(Trigger3, Echo3);
  b = obtenerCamara(Camara);


  EstadoBoton = digitalRead(but);
  EstadoBoton1 = digitalRead(but1);
  EstadoBoton2 = digitalRead(but2);

  if ((EstadoBoton == HIGH)) {
    estado = !estado;
  }
  if ((EstadoBoton1 == HIGH)) {
    estado1 = !estado1;
  }
  if ((EstadoBoton2 == HIGH)) {
    estado2 = !estado1;
  }

  if (estado == true) {
    digitalWrite(Motores, HIGH);
    Serial.print("MOTOR ON");
    if (d1 <= 30 || d2 <= 30 || d3 <= 30) {
      Serial.print("COITO");
      digitalWrite(Motores, LOW);
      digitalWrite(Buzzer, HIGH);
    } else if (b) {

      digitalWrite(Motores, LOW);
      digitalWrite(Buzzer, HIGH);
    } else {
      digitalWrite(Motores, HIGH);
      digitalWrite(Buzzer, LOW);
    }
    delay(10);



  } else {
    digitalWrite(Motores, LOW);
  }
  if (estado1 == true) {
    digitalWrite(Buzzer, HIGH);
    Serial.print("BUT2 ON");



  } else {
    digitalWrite(Buzzer, LOW);
  }
}


long obtenerDistancia(int Trigger, int Echo) {
  long t;
  long d;

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  t = pulseIn(Echo, HIGH);
  d = t / 59;
  return d;
}

bool obtenerCamara(int Camara) {
  //Contiene el código de la IA que interpreta la imagen que recibe a partir de la salida serial de la cámara (Pin Camara)
  //el algoritmo interpreta y envía un True en caso de que algun objeto se muestre frente a la cámara ocupando un gran tamaño
  //significando que hay un objeto cerca, envía un False cuando no se esté mostrando nada
  bool b = false;
  return b;
}

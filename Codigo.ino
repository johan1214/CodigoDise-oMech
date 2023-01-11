const int Trigger1 = 2;   //Pin digital 2 para el Trigger del sensor
  const int Echo1 = 3;   //Pin digital 3 para el Echo del sensor
  
  
  const int Trigger2 = 8;   //Pin digital 8 para el Trigger del sensor
  const int Echo2 = 9;   //Pin digital 9 para el Echo del sensor
  
  
  const int Trigger3 = 11;   //Pin digital 11 para el Trigger del sensor
  const int Echo3 = 12;   //Pin digital 12 para el Echo del sensor
  
  
  const int Motores= 10; //Pin digital 10 para los motores
  
  const int Camara= 14;
  
  const int Buzzer= 7;
  void setup() {
    Serial.begin(9600);//iniciailzamos la comunicación
    pinMode(Trigger1, OUTPUT); //pin como salida
    pinMode(Echo1, INPUT);  //pin como entrada
    digitalWrite(Trigger1, LOW);//Inicializamos el pin con 0
    pinMode(Trigger2, OUTPUT); //pin como salida
    pinMode(Echo2, INPUT);  //pin como entrada
    digitalWrite(Trigger2, LOW);//Inicializamos el pin con 0
    pinMode(Trigger3, OUTPUT); //pin como salida
    pinMode(Echo3, INPUT);  //pin como entrada
    pinMode(Camara, INPUT);
    pinMode(Motores, OUTPUT);
    pinMode(Buzzer, OUTPUT);
    digitalWrite(Trigger3, LOW);//Inicializamos el pin con 0
  }
  
  
  void loop()
  {
    bool b;
    long d1=obtenerDistancia(Trigger1,Echo1);
    long d2=obtenerDistancia(Trigger2,Echo2);
    long d3=obtenerDistancia(Trigger3,Echo3);
    b=obtenerCamara(Camara);
    if(d1>= 30 && d2 >=30 && d3>=30){
      digitalWrite(Motores, LOW);
      digitalWrite(Buzzer,HIGH);
    }
    else if(b){
      digitalWrite(Motores, LOW);
      digitalWrite(Buzzer,HIGH);
    }
    else{
      digitalWrite(Motores, HIGH);
    }
    delay(10); 
  }
  
  
  long obtenerDistancia(int Trigger, int Echo){
      long t; //timepo que demora en llegar el eco
      long d; //distancia en centimetros
      
      
      digitalWrite(Trigger, HIGH);
      delayMicroseconds(10);          //Enviamos un pulso de 10us
      digitalWrite(Trigger, LOW);
      t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
      d = t/59;             //escalamos el tiempo a una distancia en cm
      return d;
            
  }
  
  bool obtenerCamara(int Camara){
    //Contiene el código de la IA que interpreta la imagen que recibe a partir de la salida serial de la cámara (Pin Camara)
    //el algoritmo interpreta y envía un True en caso de que algun objeto se muestre frente a la cámara ocupando un gran tamaño
    //significando que hay un objeto cerca, envía un False cuando no se esté mostrando nada
    bool b=true;
    return b;
  }
  

int in1 = 6;
int in2 = 7;
int enA = 9;

//motor two

int in3 = 4;
int in4 = 5;
int enB = 3;

String data;
void setup() {
   pinMode(enA, OUTPUT);
   pinMode(in1, OUTPUT);
   pinMode(in2, OUTPUT);
   pinMode(enB, OUTPUT);
   pinMode(in3, OUTPUT);
   pinMode(in4, OUTPUT);
}
void loop(){
data=check(analogRead(A0))+check(analogRead(A1))+check(analogRead(A2))+check(analogRead(A3));
if(data=="0110"){
  go(100,100);
}
else if(data=="0010"){
  go(100,50);
}
else if(data=="0100"){
  go(50,100);
}
else if(data=="0011"){
  go(100,0);
}
else if(data=="1100"){
  go(0,100);
}
else if(data=="0000"){
  go(-100,-100);
}
else if(data=="1111"){
  go(-100,100);
}
else if(data=="0001"){
  go(100,-100);
}  
else if(data=="1000"){
  go(-100,100);
} 
else if(data=="0111"){
  go(100,-100);
  }
    
}
  String check(int val){
    String a;
    if(val>500){
      a="1";
    }
    else{
      a="0";
    }
    return a;
  }

  void go(int left,int right){
  if (left>0){
    digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enB,left);
  }
  if(left <0){
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(enB,0-left);  
  }
  if(right>0){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(enA,right); 
  }
  if(right<0){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(enA ,0-right); 
  }
  delay(300);
  }

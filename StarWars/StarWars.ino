#define BUZZER_PIN = 3,
#define LDR_PIN = A0
#define PORT_1 = 8,
#define PORT_2 = 10,
#define PORT_3 = 7,
#define NOTE_6 = 3136.00,
#define NOTE_3 = 2637.20,
#define NOTE_7 = 3951.40,
#define NOTE_2_H = 4698.40,
#define NOTE_3_H = 5274.00,
#define NOTE_4_dz = 2960.00,
#define HALF = 400,
#define QUATRO = 200,
#define EIGHT = 100,
#define FULL = 800

void setup()
{
  pinMode(BUZZER_PIN, OUTPUT);
  delay(2000);
  playStarWars();
}

void playStarWars() {
  SW(HALF, HALF, NOTE_6, getLPort(NOTE_6));
  SW(HALF, HALF, NOTE_6, getLPort(NOTE_6));
  SW(HALF, HALF, NOTE_6, getLPort(NOTE_6));
  SW(HALF, QUATRO, NOTE_3, getLPort(NOTE_3));
  SW(EIGHT, EIGHT, NOTE_7, getLPort(NOTE_7));
  SW(HALF, HALF, NOTE_6, getLPort(NOTE_6));
  
  SW(HALF, QUATRO, NOTE_3, getLPort(NOTE_3));
  SW(EIGHT, EIGHT, NOTE_7, getLPort(NOTE_7));
  SW(HALF, FULL, NOTE_6, getLPort(NOTE_6));
  
  SW(HALF, HALF, NOTE_2_H, getLPort(NOTE_2_H));
  SW(HALF, HALF, NOTE_2_H, getLPort(NOTE_2_H));
  SW(HALF, HALF, NOTE_2_H, getLPort(NOTE_2_H));
  SW(HALF, QUATRO, NOTE_3_H, getLPort(NOTE_3_H));
  SW(EIGHT, EIGHT, NOTE_7, getLPort(NOTE_7));
  SW(HALF, HALF, NOTE_4_dz, getLPort(NOTE_4_dz));
  
  SW(HALF, QUATRO, NOTE_3, getLPort(NOTE_3));
  SW(EIGHT, EIGHT, NOTE_7, getLPort(NOTE_7));
  SW(HALF, FULL, NOTE_6, getLPort(NOTE_6));
}

void SW(int _tone, int pause, int nota, int l_port) {
  digitalWrite(l_port, HIGH);

  tone(BUZZER_PIN, nota, _tone);

  delay(_tone);

  digitalWrite(l_port, LOW);

  delay(pause);
}

int getLPort(double nota) {
  if (nota == NOTE_6 || nota == NOTE_4_dz) {
    return PORT_1;  
  }  
  if (nota == NOTE_3 || nota == NOTE_7) {
    return PORT_2;  
  }
  if (nota == NOTE_2_H || nota == NOTE_3_H) {
    return PORT_3;  
  }
}

void loop()
{
}

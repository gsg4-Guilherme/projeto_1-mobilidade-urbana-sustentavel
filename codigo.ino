int motorA_1A = 10;  // Motor J1 - A1A
int motorA_1B = 11;  // Motor J1 - A1B  
int motorB_1A = 12;  // Motor J2 - B1A
int motorB_1B = 13;  // Motor J2 - B1B
int velocidade = 156;

int esq1  = 2;  // Jogador 1 - A
int meio1 = 3;  // Jogador 1 - B
int dir1  = 4;  // Jogador 1 - C

int esq2  = 5;  // Jogador 2 - A
int meio2 = 6;  // Jogador 2 - B
int dir2  = 7;  // Jogador 2 - C

int pontuacaoJ1 = 0;
int pontuacaoJ2 = 0;
int perguntaAtual = 0;

int respostaCorretaPergunta[9] = {1, 3, 2, 1, 2, 3, 1, 2, 3};

void setup() { 
    // Inicializa TODOS motores LOW PRIMEIRO
    digitalWrite(motorA_1A, LOW); 
    digitalWrite(motorA_1B, LOW);
    digitalWrite(motorB_1A, LOW); 
    digitalWrite(motorB_1B, LOW);
    
    // AGORA define como OUTPUT (evita estado HIGH inicial)
    pinMode(motorA_1A, OUTPUT); 
    pinMode(motorA_1B, OUTPUT);
    pinMode(motorB_1A, OUTPUT); 
    pinMode(motorB_1B, OUTPUT);
    
    // Botões
    pinMode(esq1,  INPUT_PULLUP);
    pinMode(meio1, INPUT_PULLUP);
    pinMode(dir1,  INPUT_PULLUP);
    pinMode(esq2,  INPUT_PULLUP);
    pinMode(meio2, INPUT_PULLUP);
    pinMode(dir2,  INPUT_PULLUP);
    
    Serial.begin(9600);
    Serial.println("=== JOGO INICIADO ===");
    delay(2000);
}

void loop() {
    if (perguntaAtual < 9) {
        exibirPergunta();
        aguardarResposta();
        delay(3000);  // Pausa entre perguntas
        perguntaAtual++;
    } else {
        exibirPlacarFinal();
        delay(5000);  // Mostra resultado 5 segundos
        resetJogo();  // Reinicia tudo automaticamente
    }
}

void exibirPergunta() {
    Serial.print("PERGUNTA ");
    Serial.print(perguntaAtual + 1);
    Serial.println(" - Pressione um botao!");
}

void aguardarResposta() {
    int respostaJ1 = 0, respostaJ2 = 0;
    
    // Aguarda resposta do Jogador 1
    while (respostaJ1 == 0) {
        if (digitalRead(esq1) == LOW) { 
            respostaJ1 = 1; 
            Serial.println("J1: Esquerda"); 
            delay(300); 
        }
        else if (digitalRead(meio1) == LOW) { 
            respostaJ1 = 2; 
            Serial.println("J1: Meio"); 
            delay(300); 
        }
        else if (digitalRead(dir1) == LOW) { 
            respostaJ1 = 3; 
            Serial.println("J1: Direita"); 
            delay(300); 
        }
        delay(20);
    }
    
    // Aguarda resposta do Jogador 2
    while (respostaJ2 == 0) {
        if (digitalRead(esq2) == LOW) { 
            respostaJ2 = 1; 
            Serial.println("J2: Esquerda"); 
            delay(300); 
        }
        else if (digitalRead(meio2) == LOW) { 
            respostaJ2 = 2; 
            Serial.println("J2: Meio"); 
            delay(300); 
        }
        else if (digitalRead(dir2) == LOW) { 
            respostaJ2 = 3; 
            Serial.println("J2: Direita"); 
            delay(300); 
        }
        delay(20);
    }
    
    verificarResposta(respostaJ1, respostaJ2);
}

void verificarResposta(int respostaJ1, int respostaJ2) {
    int correta = respostaCorretaPergunta[perguntaAtual];

    Serial.print("Respostas - J1:");
    Serial.print(respostaJ1);
    Serial.print(" J2:");
    Serial.println(respostaJ2);

    Serial.print("Correta: ");
    Serial.println(correta);

    // Verifica Jogador 1
    if (respostaJ1 == correta) {
        Serial.println("J1 ACERTOU!");
        pontuacaoJ1++;
        MotorJ1_GirarPor2Segundos();
    } else {
        Serial.println("J1 ERROU!");
    }

    // Verifica Jogador 2
    if (respostaJ2 == correta) {
        Serial.println("J2 ACERTOU!");
        pontuacaoJ2++;
        MotorJ2_GirarPor2Segundos();
    } else {
        Serial.println("J2 ERROU!");
    }

    Serial.print("Placar: J1=");
    Serial.print(pontuacaoJ1);
    Serial.print(" J2=");
    Serial.println(pontuacaoJ2);
}

void exibirPlacarFinal() {
    Serial.println("=== PLACAR FINAL ===");
    
    Serial.print("Jogador 1: ");
    Serial.println(pontuacaoJ1);
    
    Serial.print("Jogador 2: ");
    Serial.println(pontuacaoJ2);
    
    if (pontuacaoJ1 > pontuacaoJ2) {
        Serial.println("VENCEDOR: JOGADOR 1!");
    }
    else if (pontuacaoJ2 > pontuacaoJ1) {
        Serial.println("VENCEDOR: JOGADOR 2!");
    }
    else {
        Serial.println("EMPATE!");
    }
}

// J1 GIRA POR 2 SEGUNDOS E PARA AUTOMATICAMENTE
void MotorJ1_GirarPor2Segundos() {
    // Para J2 completamente
    digitalWrite(motorB_1A, LOW);  
    digitalWrite(motorB_1B, LOW);

    // J1 gira (forward)
    digitalWrite(motorA_1A, HIGH); 
    digitalWrite(motorA_1B, LOW);
    delay(2000);

    // Para J1
    digitalWrite(motorA_1A, LOW);  
    digitalWrite(motorA_1B, LOW);
}

// J2 GIRA POR 2 SEGUNDOS E PARA AUTOMATICAMENTE
void MotorJ2_GirarPor2Segundos() {
    // Para J1 completamente  
    digitalWrite(motorA_1A, LOW);  
    digitalWrite(motorA_1B, LOW);

    // J2 gira (forward)
    digitalWrite(motorB_1A, HIGH); 
    digitalWrite(motorB_1B, LOW);
    delay(2000);

    // Para J2
    digitalWrite(motorB_1A, LOW);  
    digitalWrite(motorB_1B, LOW);
}

void MotorJ1_Parar() {
    digitalWrite(motorA_1A, LOW);
    digitalWrite(motorA_1B, LOW);  // ← CORRIGIDO: digitalWrite
}

void MotorJ2_Parar() {
    digitalWrite(motorB_1A, LOW);
    digitalWrite(motorB_1B, LOW);  // ← CORRIGIDO: digitalWrite
}

void MotorParar() {
    digitalWrite(motorA_1A, LOW); 
    digitalWrite(motorA_1B, LOW);
    digitalWrite(motorB_1A, LOW);
    digitalWrite(motorB_1B, LOW);
}

void resetJogo() {
    pontuacaoJ1 = 0;
    pontuacaoJ2 = 0;
    perguntaAtual = 0;

    MotorParar();
    delay(1000);

    Serial.println("=== NOVA RODADA ===");
    delay(2000);
}

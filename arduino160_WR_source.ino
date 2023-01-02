/* ======================================================================================================
   
   Curso de Arduino WR Kits Channel
   
   Aplicação para os Timers do Atmega328p (Arduino UNO, Duemilanove e outros)
   
    
   Autor: Eng. Wagner Rambo  Data: Março de 2018
    
   
   www.wrkits.com.br | facebook.com/wrkits | youtube.com/canalwrkits

    
====================================================================================================== */


// ======================================================================================================
// --- Mapeamento de Hardware ---
#define   led   PB5


// ======================================================================================================
// --- Constantes ---
const uint16_t T1_init = 0;
const uint16_t T1_comp = 31250;


// ======================================================================================================
// --- Interrupção ---
ISR(TIMER1_COMPA_vect)
{
  
  TCNT1 = T1_init;      //reinicializa TIMER1
  PORTB ^= (1 << led);  //inverte nível lógico do pino do led
  
} //end ISR


// ======================================================================================================
// --- Configurações Iniciais ---
void setup()
{
   DDRB |= (1 << led);  //configura pino do led como saída

   //Modo de Comparação
   TCCR1A = 0;

   //Prescaler 1:256
   TCCR1B |=  (1 << CS12);
   TCCR1B &= ~(1 << CS11);
   TCCR1B &= ~(1 << CS10);

   //Inicializa Registradores
   TCNT1 = T1_init;
   OCR1A = T1_comp;

   //Habilita Interrupção do Timer1
   TIMSK1 = (1 << OCIE1A);
   
  
} //end setup


// ======================================================================================================
// --- Loop Infinito ---
void loop()
{
    
  
  
} //end loop















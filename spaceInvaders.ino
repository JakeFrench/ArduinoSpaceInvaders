#include <stdio.h>
#include <stdlib.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <pgmspace.h>
#include <Printable.h>

// http://www.carlos-rodrigues.com/projects/pcd8544/
// pin 7 - Serial clock out 	(SCLK)
// pin 6 - Serial data out	(DIN)
// pin 5 - Data/Command select 	(D/C)
// pin 4 - LCD chip select	(CE)
// pin 3 - LCD reset	 	(RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
uint8_t  spaceShip[5]    PROGMEM = {0x3c, 0x1e, 0x1f, 0x1e, 0x3c};
uint8_t  spaceAlien[5]   PROGMEM = {0x1e, 0x0b, 0x1f, 0x0b, 0x1e};
uint8_t  spaceMissile[5] PROGMEM = {0x00, 0x1b, 0x00, 0x1b, 0x00}; 
uint8_t  spaceEnergy[5]  PROGMEM = {0x1f, 0x15, 0x1f, 0x15, 0x1f};


uint8_t  spaceShipEnergy[7][5] PROGMEM = { {0xff, 0xff, 0xdb, 0xdb, 0xdb},
                                           {0xfe, 0xc1, 0xc1, 0xc1, 0xfe},
                                           {0xfe, 0xe1, 0xe1, 0xe1, 0xfe},
                                           {0xfe, 0xf1, 0xf1, 0xf1, 0xfe},
                                           {0xfe, 0xf9, 0xf9, 0xf9, 0xfe},
                                           {0xfe, 0xfd, 0xfd, 0xfd, 0xfe},
                                           {0xfe, 0xff, 0xff, 0xff, 0xfe} };

uint8_t  spaceShipAmmo[5][5]   PROGMEM = { {0xff, 0xff, 0xdb, 0xdb, 0xdb},
                                           {0xc0, 0xc0, 0xc0, 0xc0, 0xc0},
                                           {0xf0, 0xf0, 0xf0, 0xf0, 0xf0},
                                           {0xfc, 0xfc, 0xfc, 0xfc, 0xfc},
                                           {0xff, 0xff, 0xff, 0xff, 0xff} };


uint8_t MaddisonTitle[] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80,
0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0xF8, 0xC0, 0x00, 0x00, 0x38, 0x38,
0x30, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80,
0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0x07, 0x03, 0x07, 0xFF, 0xFF, 0x03, 0x03, 0xFF,
0xFF, 0xFC, 0x00, 0xCC, 0xEF, 0xEF, 0x63, 0x73, 0xFF, 0xFF, 0xFC, 0x00, 0xFC, 0xFE, 0xFF, 0x03,
0x03, 0x03, 0xFF, 0xFF, 0x70, 0x20, 0xFE, 0xDF, 0x07, 0x03, 0x03, 0x07, 0xFF, 0xFF, 0x00, 0x00,
0xFF, 0xFF, 0x00, 0x00, 0x00, 0x9F, 0xBF, 0x33, 0x73, 0xF7, 0xEF, 0xC4, 0x00, 0xFE, 0xFF, 0x87,
0x03, 0x03, 0x87, 0xFF, 0xFE, 0x70, 0xFF, 0xFF, 0xFF, 0x07, 0x03, 0x03, 0xFF, 0xFF, 0xF8, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00,
0x00, 0x03, 0x07, 0x07, 0x00, 0x03, 0x07, 0x07, 0x06, 0x06, 0x07, 0x07, 0x07, 0x04, 0x01, 0x03,
0x07, 0x06, 0x06, 0x07, 0x07, 0x07, 0x00, 0x00, 0x01, 0x07, 0x07, 0x06, 0x06, 0x07, 0x07, 0x07,
0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x07, 0x07, 0x06, 0x06, 0x07, 0x07, 0x03, 0x00, 0x01,
0x03, 0x07, 0x06, 0x06, 0x07, 0x07, 0x01, 0x00, 0x03, 0x07, 0x07, 0x00, 0x00, 0x00, 0x07, 0x07,
0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0,
0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xE0, 0x40, 0x00, 0xC0, 0xC0,
0xE0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xE0, 0xE0, 0xE0, 0xC0, 0xC0, 0x00, 0x00,
0xFE, 0xFF, 0xFE, 0xE0, 0xE0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x0E, 0xEE, 0xCE, 0x04, 0x00, 0x80,
0xC0, 0xE0, 0xE0, 0x60, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x7F, 0xFF, 0xE3, 0x80, 0x80, 0xC1, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0xF3,
0xFF, 0xDC, 0x8C, 0x8C, 0xDF, 0xFF, 0xFF, 0x80, 0x00, 0xFF, 0xFF, 0xC0, 0x80, 0x80, 0xFF, 0xFF,
0x7F, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0xFF, 0xFF, 0x00,
0x00, 0x7F, 0xFF, 0xE1, 0x80, 0x80, 0xC0, 0xF3, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x0E, 0x1F, 0x3F, 0x3B, 0x39, 0x3F, 0x1F, 0x0F, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00,
0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x1F, 0x1F, 0x01, 0x01, 0x01,
0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, };


uint8_t gameOverImg[] PROGMEM =
{0x00, 0x00, 0x00, 0xF0, 0x38, 0x1C, 0x0C, 0x84, 0xC4, 0xC4, 0xC4, 0xC4, 0x84, 0x04, 0x0C, 0x1C,
0xF8, 0xF0, 0xE0, 0xC0, 0x00, 0x00, 0xF0, 0xF8, 0x3C, 0x1C, 0x0C, 0x84, 0xC4, 0xC4, 0xC4, 0xC4,
0x84, 0x04, 0x0C, 0x3C, 0xF8, 0xF0, 0xE0, 0xC0, 0x00, 0x00, 0xFC, 0xFC, 0x04, 0x04, 0x04, 0x0C,
0x3C, 0x78, 0x38, 0x1C, 0x0C, 0x04, 0x04, 0x04, 0xFC, 0xFC, 0xF8, 0xF0, 0x00, 0x00, 0xFC, 0xFC,
0x04, 0x04, 0x04, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xCC, 0xFC, 0xFC, 0xF8, 0xF0,
0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x80, 0x00, 0x00, 0x1F, 0x3F, 0x23, 0x23, 0x23, 0x03, 0x03,
0x03, 0x83, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xE3, 0xE3, 0xE3,
0xE3, 0xE3, 0xE3, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00,
0x00, 0xFE, 0xFC, 0xFC, 0xFC, 0xFC, 0xFE, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
0xFF, 0xFF, 0x00, 0x00, 0x00, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x38, 0x3F, 0x3F, 0x7F, 0xFF, 0xFF,
0xC3, 0x83, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E,
0x1E, 0x1E, 0x1F, 0x1F, 0x1F, 0x1F, 0x0F, 0x07, 0x00, 0x00, 0x07, 0x0F, 0x0E, 0x1E, 0x1E, 0x1F,
0x1F, 0x1F, 0x1F, 0x07, 0x07, 0x0E, 0x1E, 0x1E, 0x1F, 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x07, 0x0F,
0x1E, 0x1E, 0x1E, 0x1F, 0x1F, 0x1F, 0x1F, 0x07, 0x0F, 0x0E, 0x1E, 0x1E, 0x1F, 0x1F, 0x1F, 0x1F,
0x00, 0x00, 0x07, 0x0F, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E,
0x1F, 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x70, 0x38, 0x18, 0x08, 0x88, 0x88,
0x88, 0x88, 0x08, 0x08, 0x18, 0x78, 0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0xF8, 0xF8, 0x08, 0x08,
0x08, 0xF8, 0xF8, 0xF0, 0xE0, 0xE0, 0xF8, 0x08, 0x08, 0x08, 0xF8, 0xF8, 0xF0, 0xE0, 0x00, 0x00,
0xF8, 0xF8, 0x08, 0x08, 0x08, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0xF8, 0xF8,
0xF0, 0xE0, 0x00, 0x00, 0xF8, 0xF8, 0x08, 0x08, 0x08, 0x88, 0x88, 0x88, 0x88, 0x88, 0x08, 0x18,
0x38, 0x70, 0xE0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x3F,
0x7F, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x7F, 0xFF,
0xC0, 0x80, 0x00, 0x0F, 0x1F, 0x3F, 0x7F, 0x1F, 0x0F, 0x00, 0x80, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF,
0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xF1, 0xF1, 0xF1, 0xF1, 0xF1, 0xF1, 0xF1, 0xFF, 0xFF,
0xFF, 0xFF, 0x87, 0x07, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xE3, 0xE3, 0xC3, 0xC3, 0x83,
0x03, 0x00, 0x20, 0x60, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0E,
0x1E, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x3C, 0x3E, 0x3F, 0x3F, 0x3F, 0x1F, 0x0F, 0x00, 0x00,
0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x1E, 0x38, 0x38, 0x3C, 0x3E, 0x3F, 0x3F, 0x3F, 0x1F, 0x0F,
0x07, 0x03, 0x00, 0x00, 0x0F, 0x1F, 0x3C, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38,
0x38, 0x3C, 0x3F, 0x3F, 0x3F, 0x3F, 0x00, 0x00, 0x0F, 0x1F, 0x38, 0x38, 0x3C, 0x3F, 0x3F, 0x3F,
0x3F, 0x0F, 0x1F, 0x38, 0x38, 0x3C, 0x3F, 0x3F, 0x3F, 0x3F, 0x00, 0x00 };



                                  
uint8_t const MaxAmmoSize = 12; // max ammo size
bool CollisionTest( uint8_t xPlayer, uint8_t yPlayer, uint8_t xAlien, uint8_t yAlien );
bool collisionAlien  = false;
unsigned int xPlayer();
unsigned int yPlayer();
float xFilter[2], yFilter[2];
void gameOver();


// used for sound effects
const uint8_t audioPin  = 8;   // digital pin 8
const uint8_t energyPin = 13;  // digital pin 13
const uint8_t ammoPin   = 12;  // digital pin 12
const long interval     = 300; // interval at which to call function (milliseconds)
long previousMillis     = 0;   // will store last time function was called

void buzzer( byte soundType );

/*****************************************************************************************/
// Bass class - has a form/shape, x and y position 
// also has a method of moving, though its not defined what this is  
class Sprite
{
  public:
    Sprite(uint8_t  *const spacePtrIn, uint8_t xInit, uint8_t yInit);
    virtual void Move() = 0;
    void Render() { if(Status) display.drawBitmap(x,y, spacePtr, 5, 6, BLACK); }
    uint8_t getX()      const { return x; } 
    uint8_t getY()      const { return y; }
    uint8_t getAmmo()   const { return Ammo; }
    uint8_t getEnergy() const { return energyLevel; }
    bool    getStatus() const { return Status; }
    
    void setCoord( uint8_t setx, uint8_t sety ) { x = setx; y = sety;}
    void setEnergy( uint8_t e)                  { energyLevel = e; }
    void setStatus( bool s)                     { Status = s; }
 protected:
    bool Status;
    uint8_t  *spacePtr;
    uint8_t x, y, Ammo, energyLevel;
};

// Sprite constructor
Sprite::Sprite(uint8_t  *const spacePtrIn, uint8_t xInit, uint8_t yInit)
{
  energyLevel = 1;
  Ammo = 1;
  x = xInit;
  y = yInit;
  spacePtr = spacePtrIn;
}



// Derived class "Missile", also a sprite and has a specific form/shape, and specific (x,y) derived from input sprite
// also has a simple way of moving
class Missile : public Sprite
{
public:
   Missile(): Sprite(&spaceMissile[0], 0, 0) { Status = true; energyLevel = 1; MissileDirection = 0; Ammo = 0; }
   void setMissileDirection( bool dir )      { MissileDirection = dir; }
   virtual void Move();
private:
   bool MissileDirection;
};

void Missile::Move()
{
  if( MissileDirection == 0 )
    y = y + 3;
  else
    y = y - 3;
  
  if( (y > 48) || (y < 2) )
    setEnergy( 0 ); 
  Render();
}





/*****************************************************************************************/
// Derived class "Alien" - has a specific form/shape, and specific (x,y) position
// also hase a specific way of moving
class Alien : public Sprite
{
public:
   Alien(); 
   virtual void Move();
   Missile* getMissile() { return &bulletBelt[0]; }
private:
   bool ShipDirection;
   uint8_t fire;
   Missile bulletBelt[MaxAmmoSize];
   //Missile* belt[MaxAmmoSize];
};

Alien::Alien(): Sprite(&spaceAlien[0], random(5, 75), random(4, 10))
{
  Status = true;
  Ammo = MaxAmmoSize;
  energyLevel = 1;
  ShipDirection = random(0, 2);
}


void Alien::Move()
{ 
  for(int i=0; i<MaxAmmoSize; i++)
  {
    if( bulletBelt[i].getEnergy() > 0 )
      bulletBelt[i].Move();  
  }
  if( Status == 0 )
    return;
  
  if( ShipDirection )
    x++;
  else
    x--;
  if( (x < 2) || (x > 72) )
  {
    ShipDirection ^= 1; 
    y += 5;
  }
  if( y > 35 )
    y = 2;
  
  fire = random(6); 
  if( (Ammo > 0) && (x>5) && (x<80) && (fire == 1) )
  {
    buzzer( 1 );
    Ammo--;
    bulletBelt[Ammo].setEnergy(1);
    bulletBelt[Ammo].setMissileDirection(0);
    bulletBelt[Ammo].setCoord(x, y+3);
  } 
  if( Ammo ==0)
    Ammo = MaxAmmoSize;
  Render();
}
/*****************************************************************************************/
// Derived class "Energy" - has a specific form/shape, and specific (x,y) position
// also hase a specific way of moving - if touched by the spaceship then full energy is granted

class Energy : public Sprite
{
public:
   Energy(): Sprite(&spaceEnergy[0], random(5, 75), random(18, 30) ) { Status = true; energyLevel = 2; Ammo = 0; EnergyDirection = random(0,2); }
   virtual void Move();
private:
  bool EnergyDirection;
};

void Energy::Move()
{
  if( EnergyDirection )
    x++;
  else
    x--;
  y += random(-2,2); 
  if( (x < 2) || (x > 72) )
    EnergyDirection ^= 1; 
  if( (y <= 0) || (y >= 40) )
    y = random(18, 30);
  Render();
}

/*****************************************************************************************/
// Derived class "Player" - has a specific form/shape, and specific (x,y) position
// also hase a specific way of moving
class Player : public Sprite
{
public:
   Player();
   virtual void Move(); 
   void Collision( Alien *pAlien );
   void MediaOutput();
   void EnergyTest();
   Missile* getMissile()     { return &bulletBelt[0]; }
   Energy*  getEnergy()      { return &energyContainer; }
private:
   uint8_t ammoLevel;
   Missile bulletBelt[MaxAmmoSize];
   Energy energyContainer;
};



Player::Player(): Sprite(&spaceShip[0], xPlayer(), yPlayer())
{
  Status = true;
  energyLevel = 6;
  ammoLevel   = 4;
  Ammo = MaxAmmoSize; 
}

void Player::Move()
{
  // fire bullets if active
  for(uint8_t i=0; i<MaxAmmoSize; i++)
  {
    if( bulletBelt[i].getEnergy() > 0 )
      bulletBelt[i].Move();  
  }
  // move (x,y)
  x = xPlayer();  
  y = yPlayer();
 
  // fire 
  if( (Ammo > 0) && !digitalRead(2) )
  {
    Ammo--;
    bulletBelt[Ammo].setEnergy(1);
    bulletBelt[Ammo].setMissileDirection(1);
    bulletBelt[Ammo].setCoord(x, y);
    
    if( (Ammo % 3) == 0 )
      ammoLevel -= 1;
    buzzer( 0 );
  }
  
  display.drawBitmap(8,0, &spaceShipAmmo[ammoLevel][0], 5, 8, BLACK);   
  Render();
}


void Player::MediaOutput()
{
  Energy* energyContainer = this->getEnergy();
  // oh dear, game over dude
  if( (energyLevel == 0) && (energyContainer->getEnergy() == 0) )
    gameOver();
      
  unsigned long currentMillis = millis();
  // check ammo levels
  if( (Ammo == 0) && (currentMillis - previousMillis > interval) )
  {
    buzzer( 3 );
    digitalWrite(ammoPin, HIGH);
    previousMillis = currentMillis;  
  }
  else
    digitalWrite(ammoPin, LOW);

  // check energy levels
  if( (energyLevel <= 2) && (currentMillis - previousMillis > interval) )
  {
    buzzer( 4 );
    digitalWrite(energyPin, HIGH);
    previousMillis = currentMillis;  
  }
  else
    digitalWrite(energyPin, LOW);
}


void Player::EnergyTest()
{
  Energy* energyContainer = this->getEnergy();
  if( (energyContainer->getStatus() == true) && ((energyLevel <= 2) || (Ammo == 0)) )
  {
    energyContainer->Move();
    if( CollisionTest(x, y, energyContainer->getX(), energyContainer->getY()) )
    {
        buzzer( 2 );
        energyLevel = 6; // transfer energy from box to spaceship
        ammoLevel   = 4; // transfer ammo from box to spaceship
        Ammo = MaxAmmoSize; 
        uint8_t energyLevel = energyContainer->getEnergy() - 1;
        energyContainer->setEnergy( energyLevel );
        if( (energyLevel == 0) || (energyLevel > 2) )
        {
          energyContainer->setEnergy( 0 );
          energyContainer->setStatus( false );
        } 
    }
  }
}


void Player::Collision( Alien *pAlien )
{
  display.drawBitmap(0,0, &spaceShipEnergy[energyLevel][0], 5, 8, BLACK);
  if( pAlien->getEnergy() == 0 )
    return;
    
  // obtain alien and player's (x,y) and do collision check here
  Missile* bulletBeltAlien  = pAlien->getMissile();
  Missile* bulletBeltPlayer = this->getMissile();
    
  for(uint8_t i=0; i<MaxAmmoSize; i++)
  {
    if( bulletBeltAlien[i].getEnergy() > 0 )
    {
      if( !collisionAlien && CollisionTest( x, y, bulletBeltAlien[i].getX(), bulletBeltAlien[i].getY()) )
      {
        energyLevel -= 1;
        if( energyLevel == 0 )
          gameOver();
      }
//      if( energyLevel > 6 )
//        energyLevel = 6;
    }
    collisionAlien = CollisionTest( x, y, bulletBeltAlien[i].getX(), bulletBeltAlien[i].getY());
    
    
    
    if( bulletBeltPlayer[i].getEnergy() > 0 )
    {
      if( CollisionTest( bulletBeltPlayer[i].getX(), bulletBeltPlayer[i].getY(), pAlien->getX(), pAlien->getY()) )
      {
        uint8_t AlienEnergy = pAlien->getEnergy() - 1;
        if( AlienEnergy > 0 )
          pAlien->setEnergy( AlienEnergy );
        else
        {
          pAlien->setEnergy( 0 );
          pAlien->setStatus( false );
        }
      }
    }
  }
}
/*****************************************************************************************/

uint8_t const MONSTERSIZE = 8;
Player *HERO;
Alien *MonsterArray[MONSTERSIZE]; 
void setup()   
{
  HERO = new Player;
  for(uint8_t i=0; i<MONSTERSIZE; i++)
  {
    MonsterArray[i] = new Alien;
    MonsterArray[i]->setStatus( false );  
  }
  MonsterArray[0]->setStatus( true );
     
  pinMode(audioPin, OUTPUT);          // sets the digital pin as output
  pinMode(energyPin, OUTPUT);         // sets the digital pin as output
  digitalWrite(audioPin, LOW);        // don't bother with the pull up resistor 
  digitalWrite(energyPin, LOW);       // don't bother with the pull up resistor
  display.begin();                    //
  display.setContrast(60);            // initialise the nokia 5110 LCD display
  display.clearDisplay();             //
  xFilter[0] = 340;                   // x filter values
  yFilter[0] = 340;                   // y filter values
  randomSeed(xPlayer() * yPlayer());  // see the random timer  

  display.clearDisplay(); 
  buzzer( 0 );
  display.drawBitmap(0, 0, &MaddisonTitle[0], 82, 48, BLACK);
  display.display();  
  buzzer( 1 );
  delay(2000);
}

uint8_t MonsterCount = 0, LEVEL = 1, i;
void loop()
{
  display.clearDisplay(); 
  HERO->Move();             
  for(i=0; i<LEVEL; i++)
  {
    MonsterArray[i]->Move();    // this does not work
    HERO->Collision( MonsterArray[i] );
  }

  // count through all of the monster array
  // this gives total number of alien-objetcs killed
  MonsterCount = 0;
  for(i=0; i<LEVEL; i++)
  {
    if( MonsterArray[i]->getStatus() == false )
      MonsterCount++;
  } 
  // if you've killed all monsters, increment to next level and reset previous monsters   
  // level 1 gives 1 alien obj,  each with 'energy level' 1
  // level 2 gives 2 alien objs, each with 'energy level' 2
  // level 3 gives 3 alien objs, each with 'energy level' 3.. etc
  if( MonsterCount == LEVEL )
  {
    LEVEL++;
    for(i=0; i<LEVEL; i++)
    {
      MonsterArray[i]->setStatus( true ); 
      MonsterArray[i]->setEnergy( LEVEL );
      MonsterArray[i]->setCoord( random(5, 75), random(2, 38) );
    }
  }
   
  HERO->MediaOutput();
  HERO->EnergyTest();
  delay(80);
  display.display();
}



unsigned int xPlayer()
{
  float x = analogRead(2);
  float alpha = 0.85, out;   
  xFilter[1] = alpha*xFilter[0] + (1-alpha)*x;
  xFilter[0] = xFilter[1];
  
  if(xFilter[1] > 360)
    xFilter[1] = 360;
  else if(xFilter[1] < 320) 
    xFilter[1] = 320;
    
  out = map( xFilter[1], 320, 360, 82, 0 );
  return out;
}



unsigned int yPlayer()
{
  float y = analogRead(1);
  float alpha = 0.85, out;   
  yFilter[1] = alpha*yFilter[0] + (1-alpha)*y;
  yFilter[0] = yFilter[1];
  
  if(yFilter[1] > 360)
    yFilter[1] = 360;
  else if(yFilter[1] < 320) 
    yFilter[1] = 320;
    
  out = map( yFilter[1], 320, 360, 0, 42 );
  return out;
}

void gameOver()
{
 buzzer( 2 );
 while(1)
 {
    display.clearDisplay(); 
    display.drawBitmap(0, 0, &gameOverImg[0], 82, 48, BLACK);
    display.display();     
    if( digitalRead(2) != 1 )
      asm volatile ("jmp 0");
 }     
}


bool CollisionTest( uint8_t xPlayer, uint8_t yPlayer, uint8_t xAlien, uint8_t yAlien )
{
  uint8_t width = 3, height = 3;
  if( ((xPlayer+width) >= xAlien)  && (xPlayer <= (xAlien+width))  &&
      ((yPlayer+height) >= yAlien) && (yPlayer <= (yAlien+height)) )
    return true;
  else
    return false;
}


void buzzer( byte soundType )
{
  unsigned int i;
  switch( soundType )
  {
    case( 0 ):  // spaceship fire
      for(i=100; i<200; i++)
      {
        digitalWrite(audioPin, HIGH);   // sets the pin on
        delayMicroseconds((int)i/2);        // pauses for 50 microseconds      
        digitalWrite(audioPin, LOW);    // sets the pin off
        delayMicroseconds((int)i/2);
      }
      break;

    case( 1 ):  // alien ship fire
      for(i=400; i<500; i++)
      {
        digitalWrite(audioPin, HIGH);   // sets the pin on
        delayMicroseconds((unsigned int)i/4);    // pauses for 50 microseconds      
        digitalWrite(audioPin, LOW);    // sets the pin off
        delayMicroseconds((unsigned int)i/4);
      }
      break;     
      
      case( 2 ): // sound of rescue box
        for(i=300; i<400; i++)
        {
         digitalWrite(audioPin, HIGH);   // sets the pin on
         delayMicroseconds((unsigned int)i/2);    // pauses for 50 microseconds      
         digitalWrite(audioPin, LOW);    // sets the pin off
         delayMicroseconds((unsigned int)i/2);
        }    
        for(i=400; i>300; i--)
        { 
         digitalWrite(audioPin, HIGH);   // sets the pin on
         delayMicroseconds((unsigned int)i/2);    // pauses for 50 microseconds      
         digitalWrite(audioPin, LOW);    // sets the pin off
         delayMicroseconds((unsigned int)i/2);
        }
      break;
      
      case( 3 ): // sound of running out of ammo
        for(i=8000; i<8006; i++)
        {
          digitalWrite(audioPin, HIGH);   // sets the pin on
          delayMicroseconds((unsigned int)i/2);        // pauses for 50 microseconds      
          digitalWrite(audioPin, LOW);    // sets the pin off
          delayMicroseconds((unsigned int)i/2);
        }
      break;   
 
      case( 4 ):  // sound of running out of energy 
       for(i=3000; i<3006; i++)
       {
          digitalWrite(audioPin, HIGH);   // sets the pin on
          delayMicroseconds((unsigned int)i/2);        // pauses for 50 microseconds      
          digitalWrite(audioPin, LOW);    // sets the pin off
          delayMicroseconds((unsigned int)i/2);
        }
      break;   
    
    
      default : 
          buzzer( 0 );
  }
}


 

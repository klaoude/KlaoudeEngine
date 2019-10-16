CC = g++
AR = ar
CFLAGS = -fPIC $(shell sdl2-config --cflags) -I../Deps/include/
LDFLAGS_SHARED = -shared $(shell sdl2-config --libs)
LDFLAGS_STATIC = $(shell sdl2-config --libs)
SHARED = ../bin/libKlaoudeEngine.so
STATIC = ../bin/libKlaoudeEngine.a

all: $(SHARED) $(STATIC)

$(STATIC): AudioEngine.o Camera2D.o DebugRenderer.o Errors.o GLSLProgram.o ImageLoader.o IMainGame.o InputManager.o IOManager.o KlaoudeEngine.o ParticleBatch2D.o ParticleEngine2D.o picoPNG.o RessourceManager.o ScreenList.o SpriteBatch.o Sprite.o SpriteFont.o TextureCache.o Timing.o Window.o 
		$(AR) -cvq $(STATIC) *.o
		$(AR) -t $(STATIC)

$(SHARED): AudioEngine.o Camera2D.o DebugRenderer.o Errors.o GLSLProgram.o ImageLoader.o IMainGame.o InputManager.o IOManager.o KlaoudeEngine.o ParticleBatch2D.o ParticleEngine2D.o picoPNG.o RessourceManager.o ScreenList.o SpriteBatch.o Sprite.o SpriteFont.o TextureCache.o Timing.o Window.o 
		$(CC) -o $(SHARED) *.o $(LDFLAGS_SHARED)

AudioEngine.o  : AudioEngine.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
 
Camera2D.o  : Camera2D.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
 
DebugRenderer.o  : DebugRenderer.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
 
Errors.o  : Errors.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
 
GLSLProgram.o  : GLSLProgram.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
 
ImageLoader.o  : ImageLoader.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
 
IMainGame.o  : IMainGame.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
 
InputManager.o  : InputManager.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
 
IOManager.o  : IOManager.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
 
KlaoudeEngine.o  : KlaoudeEngine.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
 
ParticleBatch2D.o  : ParticleBatch2D.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
 
ParticleEngine2D.o  : ParticleEngine2D.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
 
picoPNG.o  : picoPNG.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
 
RessourceManager.o  : RessourceManager.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
 
ScreenList.o  : ScreenList.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
 
SpriteBatch.o  : SpriteBatch.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
 
Sprite.o  : Sprite.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
 
SpriteFont.o  : SpriteFont.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
 
TextureCache.o  : TextureCache.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
 
Timing.o  : Timing.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
 
Window.o  : Window.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
IDIR =.
# CC=g++ -framework OpenGL -framework GLUT -framework Foundation -I/usr/local/Cellar/sdl/1.2.15_1/include -I/Users/lucas/Downloads/SDL_ttf-2.0.11/ -I/usr/local/Cellar/sdl/1.2.15_1/include/SDL -I./Include/ -I/Users/lucas/Downloads/SDL_image-1.2.12/
CC=g++ -std=c++11 -g -Wall  -I./Include/ -I./Include/sdl
# CC=g++ -g -Wall -framework OpenGL -framework GLUT -framework GLKit -framework CoreFoundation -framework Carbon -framework Foundation -framework CoreVideo -framework AudioUnit -framework Cocoa -framework IOKit -I./Include/ -I./Include/sdl
CFLAGS=-framework OpenGL -framework GLUT -framework GLKit -framework CoreFoundation -framework Carbon -framework Foundation -framework CoreVideo -framework AudioUnit -framework Cocoa -framework IOKit

ODIR=obj
LDIR =./Lib

LIBS=-lm -L./Lib -lSDLmain -lSDL_ttf -lSDL_image -lSDL -lGlEW -lfreetype 

_DEPS = T3D/Animation.h T3D/Billboard.h T3D/Bone.h T3D/Camera.h T3D/Colour.h T3D/Component.h T3D/Cube.h T3D/Cube2.h T3D/Pyramid.h T3D/Cylinder.h T3D/Lamp.h T3D/Robot.h T3D/Key.h T3D/Key2.h T3D/DiagMessageTask.h T3D/DrawTask.h T3D/Font.h T3D/FontCache.h T3D/GLRenderer.h T3D/GLShader.h T3D/GLTestApplication.h T3D/GLTestRenderer.h T3D/GameObject.h T3D/Input.h T3D/KeyboardController.h T3D/Light.h T3D/LookAtBehaviour.h T3D/Material.h T3D/Math.h T3D/Matrix3x3.h T3D/Matrix4x4.h T3D/Mesh.h T3D/Music.h T3D/ParticleBehaviour.h T3D/ParticleEmitter.h T3D/ParticleGravity.h T3D/PerfLogTask.h T3D/Plane.h T3D/PlaneMesh.h T3D/Quaternion.h T3D/Renderer.h T3D/RotateBehaviour.h T3D/Shader.h T3D/ShaderTest.h T3D/Sound.h T3D/SoundManager.h T3D/SoundTestTask.h T3D/Sphere.h T3D/Sweep.h T3D/SweepPath.h T3D/T3DApplication.h T3D/T3DTest.h T3D/Task.h T3D/Terrain.h T3D/TerrainFollower.h T3D/Texture.h T3D/Transform.h T3D/Tutorial1.h T3D/Tutorial4.h T3D/Assignment1Test.h T3D/Vector3.h T3D/Vector4.h T3D/WinGLApplication.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = T3D/Animation.o T3D/Billboard.o T3D/Bone.o T3D/Camera.o T3D/Colour.o T3D/Component.o T3D/Cube.o T3D/Cube2.o T3D/Pyramid.o T3D/Cylinder.o T3D/Lamp.o T3D/Robot.o T3D/Key.o T3D/Key2.o T3D/DiagMessageTask.o T3D/DrawTask.o T3D/Font.o T3D/FontCache.o T3D/GLRenderer.o T3D/GLShader.o T3D/GLTestApplication.o T3D/GLTestRenderer.o T3D/GameObject.o T3D/Input.o T3D/KeyboardController.o T3D/Light.o T3D/LookAtBehaviour.o T3D/Main.o T3D/Material.o T3D/Math.o T3D/Matrix3x3.o T3D/Matrix4x4.o T3D/Mesh.o T3D/ParticleBehaviour.o T3D/ParticleEmitter.o T3D/ParticleGravity.o T3D/PerfLogTask.o T3D/Plane.o T3D/PlaneMesh.o T3D/Quaternion.o T3D/Renderer.o T3D/RotateBehaviour.o T3D/Shader.o T3D/ShaderTest.o T3D/Sphere.o T3D/Sweep.o T3D/SweepPath.o T3D/T3DApplication.o T3D/T3DTest.o T3D/Task.o T3D/Terrain.o T3D/TerrainFollower.o T3D/Texture.o T3D/Transform.o T3D/Tutorial1.o T3D/Tutorial4.o T3D/Assignment1Test.o T3D/WinGLApplication.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< 

T3D/t3d: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~


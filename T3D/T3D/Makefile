IDIR =.
CC=g++
CFLAGS=-Wall -framework OpenGL -framework GLUT -framework GLKit -framework CoreFoundation -framework Carbon -framework Foundation -framework CoreVideo -framework AudioUnit -framework Cocoa -framework IOKit -I../Include/ -I$(IDIR)

ODIR=obj
LDIR =../Lib

LIBS=-L../Lib -lm -lSDL -lSDLmain -lSDL_ttf -lSDL_image -lGlEW -lfreetype 

_DEPS = Animation.h Billboard.h Bone.h Camera.h Colour.h Component.h Cube.h DiagMessageTask.h DrawTask.h Font.h FontCache.h GLRenderer.h GLShader.h GLTestApplication.h GLTestRenderer.h GameObject.h Input.h KeyboardController.h Light.h LookAtBehaviour.h Material.h Math.h Matrix3x3.h Matrix4x4.h Mesh.h Music.h ParticleBehaviour.h ParticleEmitter.h ParticleGravity.h PerfLogTask.h Plane.h PlaneMesh.h Quaternion.h Renderer.h RotateBehaviour.h Shader.h ShaderTest.h Sound.h SoundManager.h SoundTestTask.h Sphere.h Sweep.h SweepPath.h T3DApplication.h T3DTest.h Task.h Terrain.h TerrainFollower.h Texture.h Transform.h Tutorial1.h Vector3.h Vector4.h WinGLApplication.h

DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Animation.o Billboard.o Bone.o Camera.o Colour.o Component.o Cube.o DiagMessageTask.o DrawTask.o Font.o FontCache.o GLRenderer.o GLShader.o GLTestApplication.o GLTestRenderer.o GameObject.o Input.o KeyboardController.o Light.o LookAtBehaviour.o Main.o Material.o Math.o Matrix3x3.o Matrix4x4.o Mesh.o ParticleBehaviour.o ParticleEmitter.o ParticleGravity.o PerfLogTask.o Plane.o PlaneMesh.o Quaternion.o Renderer.o RotateBehaviour.o Shader.o ShaderTest.o Sphere.o Sweep.o SweepPath.o T3DApplication.o T3DTest.o Task.o Terrain.o TerrainFollower.o Texture.o Transform.o Tutorial1.o WinGLApplication.o
# _OBJ = Animation.o Billboard.o Bone.o Camera.o Colour.o Component.o Cube.o DiagMessageTask.o DrawTask.o Font.o FontCache.o GLRenderer.o GLShader.o GLTestApplication.o GLTestRenderer.o GameObject.o Input.o KeyboardController.o Light.o LookAtBehaviour.o Main.o Material.o Math.o Matrix3x3.o Matrix4x4.o Mesh.o Music.o ParticleBehaviour.o ParticleEmitter.o ParticleGravity.o PerfLogTask.o Plane.o PlaneMesh.o Quaternion.o Renderer.o RotateBehaviour.o Shader.o ShaderTest.o Sound.o SoundManager.o SoundTestTask.o Sphere.o Sweep.o SweepPath.o T3DApplication.o T3DTest.o Task.o Terrain.o TerrainFollower.o Texture.o Transform.o Tutorial1.o WinGLApplication.o

OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

t3d: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~


#include <iostream>
#include <memory>

#include <Bones/Bones.h>
//#include "OpenGL/triRenderer.h"



int main()
{

  std::shared_ptr<Core> core = Core::Initialise();
  std::shared_ptr<GameObject> triangle = core->AddGameObject();
  std::shared_ptr<MeshRenderer> mr = triangle->AddComponents<MeshRenderer>();

  //std::shared_ptr<Mesh> mesh = core->load<Material>("shaders/simple");
  

  

  core->Start();


  /*
  for (int i = 0; i < 1000; i++)
  {
	  core->update();
  }
  */




  std::cin.get();
  return 0;
}
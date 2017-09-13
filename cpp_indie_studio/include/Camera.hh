//
// Camera.hh for Camera in /home/lucas_k/TEK2/CPP/cpp_indie_studio.VERRYIMPORTANT/indie-studio
// 
// Made by christophe lucas
// Login   <lucas_k@epitech.net>
// 
// Started on  Sun Jun  5 15:31:32 2016 christophe lucas
// Last update Sun Jun  5 15:34:21 2016 christophe lucas
//

#ifndef CAMERA_HH_
# define CAMERA_HH_

# include <irrlicht.h>

class				Camera
{
public:
				Camera(irr::scene::ISceneManager *, irr::core::vector3df);
				Camera(irr::core::vector3df);
				Camera();
				~Camera();
  
  bool				addToSceneManager(irr::scene::ISceneManager *, irr::core::vector3df);
  bool				updateTargetPosition(irr::core::vector3df);

private:
  irr::scene::ICameraSceneNode	*camera;
};

#endif // !CAMERA_HH_

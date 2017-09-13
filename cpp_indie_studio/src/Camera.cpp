//
// Camera.cpp for Camera in /home/aknin_k/rendu/tek2/cpp/indie/project/indie-studio/src
// 
// Made by Karine Aknin
// Login   <aknin_k@epitech.net>
// 
// Started on  Sun Jun  5 15:20:29 2016 Karine Aknin
// Last update Sun Jun  5 17:43:36 2016 christophe lucas
//

#include "Camera.hh"

Camera::Camera(irr::scene::ISceneManager *scene,
	       irr::core::vector3df targetPosition)
{
  camera = scene->addCameraSceneNode(NULL, irr::core::vector3df(0, 300, 0),
				     targetPosition, 15, true);
}

Camera::Camera(irr::core::vector3df targetPosition)
  : camera(NULL)
{
}

Camera::Camera()
  : camera(NULL)
{
}

Camera::~Camera()
{
}

bool        Camera::addToSceneManager(irr::scene::ISceneManager *scene,
				      irr::core::vector3df targetPosition)
{
  if (!camera)
    {
      camera = scene->addCameraSceneNode(NULL,
					 irr::core::vector3df(targetPosition.X, 150, targetPosition.Z),
					 targetPosition, 15, true);
      camera->bindTargetAndRotation(true);
      return true;
    }
  return false;
}

bool			Camera::updateTargetPosition(irr::core::vector3df targetPosition)
{
  irr::core::vector3df	newCameraPos;
  
  newCameraPos = camera->getPosition();
  newCameraPos.X = targetPosition.X;
  newCameraPos.Z = targetPosition.Z;
  camera->setTarget(targetPosition);
  camera->setPosition(newCameraPos);
}

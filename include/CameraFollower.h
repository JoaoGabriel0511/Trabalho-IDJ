#ifndef CAMERA_FOLLOWER_H
#define CAMERA_FOLLOER_H
#include "Component.h"

class CameraFollower : public Component {

    public:
        CameraFollower(GameObject& go);
        void Update(float dt);
        void Render();
        bool Is(string type);
};


#endif
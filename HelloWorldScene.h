#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

using namespace cocos2d;

class HelloWorld : public cocos2d::Layer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init() override;  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* scene();
    
    // a selector callback
    void menuCloseCallback(Ref* sender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
    
    virtual void visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags);
    void onDraw();
private:
    CustomCommand m_command;
    GLuint  m_vao;
    GLuint m_testVao;
};

#endif // __HELLOWORLD_SCENE_H__

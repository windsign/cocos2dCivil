#include "HelloWorldScene.h"
#include "AppMacros.h"
#include <fstream>
#include "GameScene.h"

USING_NS_CC;
using namespace std;

Scene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{    
    if(!Layer::init())
    {
        return false;
    }
    
    ofstream off;
    off.open("testPath");
    if (off.is_open()) {
        off<<"test"<<"\n";
    }
    
    auto program = new GLProgram;
    bool res = program->initWithFilenames("simplevs.vs", "simplefs.fs");
    program->link();
    program->updateUniforms();
    
    setGLProgram(program);
    //setGLProgram(GLProgramCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_COLOR));

    typedef struct{
        float position[2];
        float color[4];
    }vertex;
    
    vertex verteics[] = {
    {{20, 0}, {1, 0, 0, 1}},
    {{10, 17.32}, {1, 0, 0, 1}},
    {{20, 34.68}, {1, 0, 0, 1}},
    {{40, 34.68}, {1, 0, 0, 1}},
    {{50, 17.32}, {1, 0, 0, 1}},
    {{40, 0}, {1, 0, 0, 1}}
    };
    
    GLubyte indexs[]={0, 1, 2, 0, 2, 3, 0, 3, 4, 0, 4, 5};
    
    
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    
    GLuint i_vbo;
    glGenBuffers(1, &i_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, i_vbo);
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(verteics), verteics, GL_STATIC_DRAW);
    
    GLuint positionLocation = glGetAttribLocation(program->getProgram(), "a_position");
    glEnableVertexAttribArray(positionLocation);
    glVertexAttribPointer(positionLocation, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid*)offsetof(vertex, position));
    
    GLuint colorLocation = glGetAttribLocation(program->getProgram(), "a_color");
    glEnableVertexAttribArray(colorLocation);
    glVertexAttribPointer(colorLocation, 4, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid*)offsetof(vertex, color));
    
    GLuint i_ibo;
    glGenBuffers(1, &i_ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_ibo);
    
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexs), indexs, GL_STATIC_DRAW);
    
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    CHECK_GL_ERROR_DEBUG();
    
	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
	EventListenerTouchAllAtOnce* listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(HelloWorld::onTouchesBegan, this);
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
    
}

void HelloWorld::menuCloseCallback(Ref* sender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::onDraw()
{
    
    auto glProgram = getGLProgram();
    glProgram->use();
    glProgram->setUniformsForBuiltins();

    glBindVertexArray(m_vao);
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, (GLvoid*)0);

    CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, 6);
    
    glBindVertexArray(0);
    CHECK_GL_ERROR_DEBUG();
}

void HelloWorld::visit(Renderer *renderer, const Mat4& transform, uint32_t parentFlags)
{
    Layer::visit(renderer, transform, parentFlags);
    m_command.init(_globalZOrder);
    m_command.func = CC_CALLBACK_0(HelloWorld::onDraw, this);
    Director::getInstance()->getRenderer()->addCommand(&m_command);
}

void HelloWorld::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
{
	auto scene = CGameScene::create();
	auto animationScene = TransitionFade::create(0.5f, scene);
	Director::getInstance()->replaceScene(animationScene);
}
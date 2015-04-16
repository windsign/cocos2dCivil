#include "HelloWorldScene.h"
#include "AppMacros.h"
#include <fstream>
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
    /*
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        CC_CALLBACK_1(HelloWorld::menuCloseCallback,this));
    
    closeItem->setPosition(origin + Vec2(visibleSize) - Vec2(closeItem->getContentSize() / 2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", TITLE_FONT_SIZE);
    
    // position the label on the center of the screen
    label->setPosition(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height);

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize / 2) + origin);

    // add the sprite as a child to this layer
    this->addChild(sprite);
    */
    
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
    program->initWithFilenames("simplevs.vs", "simplefs.fs");
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
    /*
    auto size = Director::getInstance()->getWinSize();
    float vertercies[] = {0,0,
                        size.width, 0,
        size.width/2, size.height};
        float color[] = {0, 1, 0, 1,
                        1, 0, 0, 1,
                        0, 0, 1, 1};
        GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION | GL::VERTEX_ATTRIB_FLAG_COLOR);
        
        glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 2, GL_FLOAT, 0, 0, vertercies);
        glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_FLOAT, 0, 0, color);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        */
    glBindVertexArray(m_vao);
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, (GLvoid*)0);

    CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, 3);
    
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
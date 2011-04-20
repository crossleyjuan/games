#ifndef ENTITY_H
#define ENTITY_H

#include "animation.h"
#include "tile.h"
#include "gameengine_global.h"
#include <vector>
#include <SDL.h>

enum {
    ENTITY_TYPE_GENERIC = 0,

    ENTITY_TYPE_PLAYER
};

enum {
    ENTITY_FLAG_NONE    = 0,

    ENTITY_FLAG_GRAVITY = 0x00000001,
    ENTITY_FLAG_GHOST   = 0x00000002,
    ENTITY_FLAG_MAPONLY = 0x00000004
};

class GAMEENGINESHARED_EXPORT Entity {

    public:
        static std::vector<Entity*>    EntityList;

    protected:
        Animation      Anim_Control;

        SDL_Surface*    Surf_Entity;

    public:
        float           X;
        float           Y;
        float           centerX;
        float           centerY;

        int             Width;
        int             Height;

        bool        MoveLeft;
        bool        MoveRight;

    public:
        int     Type;

        bool        Dead;
        int     Flags;

    protected:
        float       SpeedX;
        float       SpeedY;

        float       AccelX;
        float       AccelY;

    public:
        float       MaxSpeedX;
        float       MaxSpeedY;

    protected:
        int             CurrentFrameCol;
        int             CurrentFrameRow;

    protected:
        int     Col_X;
        int     Col_Y;
        int     Col_Width;
        int     Col_Height;
        void refreshCenter();

    public:
        Entity();
        Entity(const Entity &ent);

        virtual ~Entity();

    public:
        virtual bool OnLoad(char* File, int Width, int Height, int MaxFrames);

        virtual void OnLoop();

        virtual void OnRender(SDL_Surface* Surf_Display);

        virtual void OnCleanup();

        virtual void OnAnimate();

        virtual bool OnCollision(Entity* Entity);
        virtual bool OnMapCollision();

    public:
        void    OnMove(float MoveX, float MoveY);

        void    StopMove();

    public:
        bool    Collides(int oX, int oY, int oW, int oH);

    private:
        bool    PosValid(int NewX, int NewY);

        bool    PosValidTile(Tile* Tile);

        bool    PosValidEntity(Entity* Entity, int NewX, int NewY);

protected:
    bool    CanJump;
public:
    bool    Jump();

};

class EntityCol {
    public:
        static std::vector<EntityCol>  EntityColList;

    public:
        Entity* EntityA;
        Entity* EntityB;

    public:
        EntityCol();
};

class EntityMapCol {
    public:
        static std::vector<EntityMapCol>  EntityMapColList;

    public:
        Entity* EntityA;

    public:
        EntityMapCol();
};

#endif // ENTITY_H

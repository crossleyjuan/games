#include "entity.h"
#include "surface.h"
#include "camera.h"
#include "fps.h"
#include "area.h"

std::vector<Entity*>   Entity::EntityList;

Entity::Entity() {
    Surf_Entity = NULL;

    X = 0;
    Y = 0;
//    centerX = 0;
//    centerY = 0;

    Width   = 0;
    Height  = 0;

    MoveLeft  = false;
    MoveRight = false;

    Type =  ENTITY_TYPE_GENERIC;

    Dead = false;
    Flags = ENTITY_FLAG_GRAVITY;

    SpeedX = 0;
    SpeedY = 0;

    AccelX = 0;
    AccelY = 0;

    MaxSpeedX = 5;
    MaxSpeedY = 5;

    CanJump = false;

    CurrentFrameCol = 0;
    CurrentFrameRow = 0;

    Col_X = 0;
    Col_Y = 0;

    Col_Width  = 0;
    Col_Height = 0;
}

Entity::Entity(const Entity &ent) {
    this->AccelX = ent.AccelX;
    this->AccelY = ent.AccelY;
    this->Anim_Control = ent.Anim_Control;
    this->CanJump = ent.CanJump;
    this->Col_Height = ent.Col_Height;
    this->Col_Width = ent.Col_Width;
    this->Col_X = ent.Col_X;
    this->Col_Y = ent.Col_Y;
    this->CurrentFrameCol = ent.CurrentFrameCol;
    this->CurrentFrameRow = ent.CurrentFrameRow;
    this->Dead = ent.Dead;
    this->Flags = ent.Flags;
    this->Height = ent.Height;
    this->MaxSpeedX = ent.MaxSpeedX;
    this->MaxSpeedY = ent.MaxSpeedY;
    this->MoveLeft = ent.MoveLeft;
    this->MoveRight = ent.MoveRight;
    this->X = ent.X;
    this->Y = ent.Y;
    this->centerX = ent.centerX;
    this->centerY = ent.centerY;
}

Entity::~Entity() {
}

bool Entity::OnLoad(char* File, int Width, int Height, int MaxFrames) {
    if((Surf_Entity = Surface::loadImage(File)) == NULL) {
        return false;
    }

    Surface::Transparent(Surf_Entity, 255, 0, 255);

    this->Width = Width;
    this->Height = Height;

    Anim_Control.MaxFrames = MaxFrames;
    Anim_Control.Oscillate = false;

    return true;
}

void Entity::OnLoop() {
    //We’re not Moving
    if(MoveLeft == false && MoveRight == false) {
        StopMove();
    }
    if(MoveLeft) {
        AccelX = -0.5;
    }else

    if(MoveRight) {
        AccelX = 0.5;
    }

    if(Flags & ENTITY_FLAG_GRAVITY) {
        AccelY = 0.75f;
    }

    SpeedX += AccelX * FPS::FPSControl.GetSpeedFactor();
    SpeedY += AccelY * FPS::FPSControl.GetSpeedFactor();

    if(SpeedX > MaxSpeedX)  SpeedX =  MaxSpeedX;
    if(SpeedX < -MaxSpeedX) SpeedX = -MaxSpeedX;
    if(SpeedY > MaxSpeedY)  SpeedY =  MaxSpeedY;
    if(SpeedY < -MaxSpeedY) SpeedY = -MaxSpeedY;

    OnAnimate();
    OnMove(SpeedX, SpeedY);
}

void Entity::OnRender(SDL_Surface* Surf_Display) {
    if(Surf_Entity == NULL || Surf_Display == NULL) return;
    Surface::OnDraw(Surf_Display, Surf_Entity, X - Camera::CameraControl.GetX(), Y - Camera::CameraControl.GetY(), CurrentFrameCol * Width, (CurrentFrameRow + Anim_Control.GetCurrentFrame()) * Height, Width, Height);
}

void Entity::OnCleanup() {
    if(Surf_Entity) {
        SDL_FreeSurface(Surf_Entity);
    }

    Surf_Entity = NULL;
}

void Entity::OnAnimate() {
    if(MoveLeft) {
        CurrentFrameCol = 0;
    }else
    if(MoveRight) {
        CurrentFrameCol = 1;
    }

    Anim_Control.OnAnimate();
}

bool Entity::OnCollision(Entity* Entity) {
}

bool Entity::OnMapCollision() {
}

void Entity::OnMove(float MoveX, float MoveY) {
    CanJump = false;
    if(MoveX == 0 && MoveY == 0) return;
    double NewX = 0;
    double NewY = 0;

    MoveX *= FPS::FPSControl.GetSpeedFactor();
    MoveY *= FPS::FPSControl.GetSpeedFactor();

    if(MoveX != 0) {
        if(MoveX >= 0)  NewX =  FPS::FPSControl.GetSpeedFactor();
        else            NewX = -FPS::FPSControl.GetSpeedFactor();
    }

    if(MoveY != 0) {
        if(MoveY >= 0)  NewY =  FPS::FPSControl.GetSpeedFactor();
        else            NewY = -FPS::FPSControl.GetSpeedFactor();
    }

    while(true) {
        if(Flags & ENTITY_FLAG_GHOST) {
            PosValid((int)(X + NewX), (int)(Y + NewY)); //We don’t care about collisions, but we need to send events to other entities

            X += NewX;
            Y += NewY;
        }else{
            if(PosValid((int)(X + NewX), (int)(Y))) {
                X += NewX;
            }else{
                SpeedX = 0;
            }

            if(PosValid((int)(X), (int)(Y + NewY))) {
                Y += NewY;
            }else{
                if(MoveY > 0) {
                    CanJump = true;
                }
                SpeedY = 0;
            }
        }

        MoveX += -NewX;
        MoveY += -NewY;

        if(NewX > 0 && MoveX <= 0) NewX = 0;
        if(NewX < 0 && MoveX >= 0) NewX = 0;

        if(NewY > 0 && MoveY <= 0) NewY = 0;
        if(NewY < 0 && MoveY >= 0) NewY = 0;

        if(MoveX == 0) NewX = 0;
        if(MoveY == 0) NewY = 0;

        if(MoveX == 0 && MoveY  == 0)   break;
        if(NewX  == 0 && NewY   == 0)   break;
    }

    refreshCenter();
}

void Entity::StopMove() {
    if(SpeedX > 0) {
        AccelX = -1;
    }
    if(SpeedX < 0) {
        AccelX =  1;
    }

    if(SpeedX < 2.0f && SpeedX > -2.0f) {
        AccelX = 0;
        SpeedX = 0;
    }
}

bool Entity::Collides(int oX, int oY, int oW, int oH) {
    int left1, left2;
    int right1, right2;
    int top1, top2;
    int bottom1, bottom2;
    int tX = (int)X + Col_X;
    int tY = (int)Y + Col_Y;

    left1 = tX;
    left2 = oX;

    right1 = left1 + Width - 1 - Col_Width;
    right2 = oX + oW - 1;

    top1 = tY;
    top2 = oY;

    bottom1 = top1 + Height - 1 - Col_Height;
    bottom2 = oY + oH - 1;

    if (bottom1 < top2) return false;
    if (top1 > bottom2) return false;

    if (right1 < left2) return false;
    if (left1 > right2) return false;

    return true;
}

bool Entity::PosValid(int NewX, int NewY) {
    bool Return = true;
    int StartX  = (NewX + Col_X) / TILE_SIZE;
    int StartY  = (NewY + Col_Y) / TILE_SIZE;

    int EndX    = ((NewX + Col_X) + Width - Col_Width - 1)      / TILE_SIZE;
    int EndY    = ((NewY + Col_Y) + Height - Col_Height - 1)    / TILE_SIZE;

    for(int iY = StartY;iY <= EndY;iY++) {
        for(int iX = StartX;iX <= EndX;iX++) {
            Tile* Tile = Area::AreaControl.GetTile(iX * TILE_SIZE, iY * TILE_SIZE);

            if(PosValidTile(Tile) == false) {
                return false;
            }
        }
    }

    if(Flags & ENTITY_FLAG_MAPONLY) {
    }else{
        for(int i = 0;i < EntityList.size();i++) {
            if(PosValidEntity(EntityList[i], NewX, NewY) == false) {
                return false;
            }
        }
    }

    return Return;
}

bool Entity::PosValidTile(Tile* Tile) {
    if(Tile == NULL) {
        return false;
    }
    if(Tile->TypeID == TILE_TYPE_BLOCK) {
        EntityMapCol mapCol;
        mapCol.EntityA = this;
        EntityMapCol::EntityMapColList.push_back(mapCol);

        return false;
    }

    return true;
}

bool Entity::PosValidEntity(Entity* Entity, int NewX, int NewY) {
    if(this != Entity && Entity != NULL && Entity->Dead == false &&
        Entity->Flags ^ ENTITY_FLAG_MAPONLY &&
        Entity->Collides(NewX + Col_X, NewY + Col_Y, Width - Col_Width - 1, Height - Col_Height - 1) == true) {

        // Checks to avoid duplicates
        for (std::vector<EntityCol>::iterator iter = EntityCol::EntityColList.begin()
            ; iter != EntityCol::EntityColList.end(); iter++) {
            EntityCol col = *iter;
            if ((col.EntityA == Entity) || (col.EntityB == Entity)) {
                return false;
            }
        }

        EntityCol EntityCol;

        EntityCol.EntityA = this;
        EntityCol.EntityB = Entity;

        EntityCol::EntityColList.push_back(EntityCol);

        return false;
    }

    return true;
}

bool Entity::Jump() {
    if(CanJump == false) return false;

    SpeedY = -MaxSpeedY;

    return true;
}

void Entity::refreshCenter() {
    centerX = X + (Width / 2);
    centerY = Y + (Height / 2);
}

bool Entity::IsMoving() {
    if ((SpeedX == 0) && (SpeedY == 0)) {
        return false;
    } else {
        return true;
    }
}

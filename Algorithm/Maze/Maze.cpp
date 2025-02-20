﻿#include "pch.h"
#include "ConsoleHelper.h"
#include "Board.h"
#include "player.h"

Board board;
Player player;

int main()
{
    ::srand(static_cast<unsigned int>(time(nullptr)));

    board.Init(25, &player);
    player.Init(&board);

    uint64 lastTick = 0;
    while (true)
    {
#pragma region 프레임 관리
        const uint64 currentTick = ::GetTickCount64();
        const uint64 deltaTick = currentTick - lastTick;
        lastTick = currentTick;
#pragma endregion
        // 입력

        // 로직
        player.Update(deltaTick);

        // 랜더링
        board.Render();
    }
}

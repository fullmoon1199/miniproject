void process(int direction)
{
    switch (direction)
    {
    case UP:
        for (int i = 0; i <= 3; i++)
        {
            for (int j = 0; j <= 3; j++)
            {
                subm[i][j] = game[i][j];
            }
        }
        // top not move
        for (int col = 0; col < COL; ++col)
        {
            u:
            int upcount = 0;
            for (int row = 1; row < ROW; ++row)
            {
                for (int crow = row; crow >= 1; --crow)
                {
                    if (game[0][col] == game[1][col] && game[2][col] == game[3][col] && game[3][col] != 0 && game[1][col] != 0)
                    {
                        game[0][col] *= 2;
                        game[1][col] = game[2][col] * 2;
                        game[2][col] = 0;
                        game[3][col] = 0;
                        col++;
                        goto u;
                    }

                    // last is space
                    else if (game[crow - 1][col] == 0)
                    {
                        game[crow - 1][col] = game[crow][col];
                        game[crow][col] = 0;
                    }
                    else
                    {
                        // merge
                        if (game[crow - 1][col] == game[crow][col])
                        {
                            if (upcount < 1)
                            {
                                upcount++;
                                game[crow - 1][col] *= 2;
                                game[crow][col] = 0;
                            }
                            else
                                break;
                        }
                    }
                }
            }
        }
        break;
    case DOWN:
        for (int i = 0; i <= 3; i++)
        {
            for (int j = 0; j <= 3; j++)
            {
                subm[i][j] = game[i][j];
            }
        }
        for (int col = 0; col < COL; ++col)
        {
        d:
            int dwcount = 0;
            for (int row = 2; row >= 0; --row)
            {

                for (int crow = row; crow <= 2; ++crow)
                {
                    if (game[0][col] == game[1][col] && game[2][col] == game[3][col] && game[3][col] != 0 && game[1][col] != 0)
                    {
                        game[3][col] *= 2;
                        game[2][col] = game[1][col] * 2;
                        game[0][col] = 0;
                        game[1][col] = 0;
                        col++;
                        goto d;
                    }
                    // last is space
                    else if (game[crow + 1][col] == 0)
                    {
                        game[crow + 1][col] = game[crow][col];
                        game[crow][col] = 0;
                    }
                    else
                    {
                        if (game[crow + 1][col] == game[crow][col])
                        {
                            if (dwcount < 1)
                            {
                                dwcount++;
                                game[crow + 1][col] *= 2;
                                game[crow][col] = 0;
                            }
                            else
                                break;
                        }
                    }
                }
            }
        }
        break;
    case LEFT:
        for (int i = 0; i <= 3; i++)
        {
            for (int j = 0; j <= 3; j++)
            {
                subm[i][j] = game[i][j];
            }
        }
        for (int col = 1; col < COL; ++col)
        {
            for (int ccol = col; ccol >= 1; --ccol)
            {
                for (int row = 0; row < ROW; ++row)
                {
                    if (game[row][ccol - 1] == 0)
                    {
                        game[row][ccol - 1] = game[row][ccol];
                        game[row][ccol] = 0;
                    }
                    else
                    {
                        if (game[row][ccol - 1] == game[row][ccol])
                        {
                            game[row][ccol - 1] *= 2;
                            game[row][ccol] = 0;
                        }
                    }
                }
            }
        }
        break;
    case RIGHT:
        for (int i = 0; i <= 3; i++)
        {
            for (int j = 0; j <= 3; j++)
            {
                subm[i][j] = game[i][j];
            }
        }
        for (int row = 0; row < ROW; ++row)
        {
        r:
            int rgcount = 0;
            for (int cow = 2; cow >= 0; --cow)
            {
                for (int ccow = cow; ccow <= 2; ++ccow)
                {
                    if (game[row][0] == game[row][1] && game[row][2] == game[row][3] && game[row][3] != 0 && game[row][1] != 0)
                    {
                        game[row][3] *= 2;
                        game[row][2] = game[row][1] * 2;
                        game[row][1] = 0;
                        game[row][0] = 0;
                        row++;
                        goto r;
                    }
                    // last is space
                    else if (game[row][ccow + 1] == 0)
                    {
                        game[row][ccow + 1] = game[row][ccow];
                        game[row][ccow] = 0;
                    }
                    else
                    {
                        if (game[row][ccow + 1] == game[row][ccow])
                        {
                            if (rgcount < 1)
                            {
                                rgcount++;
                                game[row][ccow + 1] *= 2;
                                game[row][ccow] = 0;
                            }
                            else
                                break;
                        }
                    }
                }
            }
        }
        break;
    case BACK:
        for (int i = 0; i <= 3; i++)
        {
            for (int j = 0; j <= 3; j++)
            {
                game[i][j] = subm[i][j];
            }
        }
    }
}
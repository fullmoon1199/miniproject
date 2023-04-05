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
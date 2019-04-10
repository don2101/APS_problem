#include <iostream>

using namespace std;


char up[3][3];
char down[3][3];
char lef[3][3];
char righ[3][3];
char front[3][3];
char back[3][3];
int n;


void operation(char oper, char direc) {
    if(oper == 'U') {
        char temp[3][3];
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                temp[i][j] = up[i][j];
            }
        }
        if(direc == '+') {
            int a = 0;
            int b = 0;
            for(int j = 0; j < 3; ++j) {
                for(int i = 2; i >= 0; --i) {
                    up[a][b] = temp[i][j];
                    b++;
                    if(b == 3) {
                        a++;
                        b = 0;
                    }
                }
            }

            char temp2[3];
            for(int i = 0; i < 3; ++i) {
                temp2[i] = back[0][i];
            }

            for(int i = 0; i < 3; ++i) {
                back[0][i] = lef[0][i];
                lef[0][i] = front[0][i];
                front[0][i] = righ[0][i];
                righ[0][i] = temp2[i];
            }
        } else {
            int a = 0;
            int b = 0;
            for(int j = 2; j >= 0; --j) {
                for(int i = 0; i < 3; ++i) {
                    up[a][b] = temp[i][j];
                    b++;
                    if(b == 3) {
                        a++;
                        b = 0;
                    }
                }
            }

            char temp2[3];
            for(int i = 0; i < 3; ++i) {
                temp2[i] = back[0][i];
            }

            for(int i = 0; i < 3; ++i) {
                back[0][i] = righ[0][i];
                righ[0][i] = front[0][i];
                front[0][i] = lef[0][i];
                lef[0][i] = temp2[i];
            }
        }
    } else if (oper == 'D') {
        char temp[3][3];
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                temp[i][j] = down[i][j];
            }
        }

        if(direc == '+') {
            int a = 0;
            int b = 0;
            for(int j = 0; j < 3; ++j) {
                for(int i = 2; i >= 0; --i) {
                    down[a][b] = temp[i][j];
                    b++;
                    if(b == 3) {
                        a++;
                        b = 0;
                    }
                }
            }

            char temp2[3];
            for(int i = 0; i < 3; ++i) {
                temp2[i] = back[2][i];
            }

            for(int i = 0; i < 3; ++i) {
                back[2][i] = righ[2][i];
                righ[2][i] = front[2][i];
                front[2][i] = lef[2][i];
                lef[2][i] = temp2[i];
            }
        } else {
            int a = 0;
            int b = 0;
            for(int j = 2; j >= 0; --j) {
                for(int i = 0; i < 3; ++i) {
                    down[a][b] = temp[i][j];
                    b++;
                    if(b == 3) {
                        a++;
                        b = 0;
                    }
                }
            }

            char temp2[3];
            for(int i = 0; i < 3; ++i) {
                temp2[i] = back[2][i];
            }

            for(int i = 0; i < 3; ++i) {
                back[2][i] = lef[2][i];
                lef[2][i] = front[2][i];
                front[2][i] = righ[2][i];
                righ[2][i] = temp2[i];
            }
        }
    } else if (oper == 'R') {
        char temp[3][3];
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                temp[i][j] = righ[i][j];
            }
        }

        if(direc == '+') {
            int a = 0;
            int b = 0;
            for(int j = 0; j < 3; ++j) {
                for(int i = 2; i >= 0; --i) {
                    righ[a][b] = temp[i][j];
                    b++;
                    if(b == 3) {
                        a++;
                        b = 0;
                    }
                }
            }

            char temp2[3];
            for(int i = 0; i < 3; ++i) {
                temp2[i] = back[i][0];
            }

            for(int i = 0; i < 3; ++i) {
                back[i][0] = up[2-i][2];
                up[2-i][2] = front[2-i][2];
                front[2-i][2] = down[2-i][2];
                down[2-i][2] = temp2[i];
            }
        } else {
            int a = 0;
            int b = 0;
            for(int j = 2; j >= 0; --j) {
                for(int i = 0; i < 3; ++i) {
                    righ[a][b] = temp[i][j];
                    b++;
                    if(b == 3) {
                        a++;
                        b = 0;
                    }
                }
            }

            char temp2[3];
            for(int i = 0; i < 3; ++i) {
                temp2[i] = back[i][0];
            }

            for(int i = 0; i < 3; ++i) {
                back[i][0] = down[2-i][2];
                down[2-i][2] = front[2-i][2];
                front[2-i][2] = up[2-i][2];
                up[2-i][2]= temp2[i];
            }
        }
    } else if (oper == 'L') {
        char temp[3][3];
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                temp[i][j] = lef[i][j];
            }
        }

        if(direc == '+') {
            int a = 0;
            int b = 0;
            for(int j = 0; j < 3; ++j) {
                for(int i = 2; i >= 0; --i) {
                    lef[a][b] = temp[i][j];
                    b++;
                    if(b == 3) {
                        a++;
                        b = 0;
                    }
                }
            }

            char temp2[3];
            for(int i = 0; i < 3; ++i) {
                temp2[i] = back[i][2];
            }

            for(int i = 0; i < 3; ++i) {
                back[i][2] = down[2-i][0];
                down[2-i][0] = front[2-i][0];
                front[2-i][0] = up[2-i][0];
                up[2-i][0] = temp2[i];
            }
        } else {
            int a = 0;
            int b = 0;
            for(int j = 2; j >= 0; --j) {
                for(int i = 0; i < 3; ++i) {
                    lef[a][b] = temp[i][j];
                    b++;
                    if(b == 3) {
                        a++;
                        b = 0;
                    }
                }
            }

            char temp2[3];
            for(int i = 0; i < 3; ++i) {
                temp2[i] = back[i][2];
            }

            for(int i = 0; i < 3; ++i) {
                back[i][2] = up[2-i][0];
                up[2-i][0] = front[2-i][0];
                front[2-i][0] = down[2-i][0];
                down[2-i][0] = temp2[i];
            }
        }
    } else if (oper == 'B') {
        char temp[3][3];
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                temp[i][j] = back[i][j];
            }
        }

        if(direc == '+') {
            int a = 0;
            int b = 0;
            for(int j = 0; j < 3; ++j) {
                for(int i = 2; i >= 0; --i) {
                    back[a][b] = temp[i][j];
                    b++;
                    if(b == 3) {
                        a++;
                        b = 0;
                    }
                }
            }

            char temp2[3];
            for(int i = 0; i < 3; ++i) {
                temp2[i] = up[0][i];
            }

            for(int i = 0; i < 3; ++i) {
                up[0][i] = righ[i][2];
                righ[i][2] = down[2][2-i];
                down[2][2-i] = lef[2-i][0];
                lef[2-i][0] = temp2[i];
            }
        } else {
            int a = 0;
            int b = 0;
            for(int j = 2; j >= 0; --j) {
                for(int i = 0; i < 3; ++i) {
                    back[a][b] = temp[i][j];
                    b++;
                    if(b == 3) {
                        a++;
                        b = 0;
                    }
                }
            }

            char temp2[3];
            for(int i = 0; i < 3; ++i) {
                temp2[i] = up[0][i];
            }

            for(int i = 0; i < 3; ++i) {
                up[0][i] = lef[2-i][0];
                lef[2-i][0] = down[2][2-i];
                down[2][i] = righ[i][2];
                righ[i][2] = temp2[i];
            }
        }
    } else if (oper == 'F') {
        char temp[3][3];
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                temp[i][j] = front[i][j];
            }
        }

        if(direc == '+') {
            int a = 0;
            int b = 0;
            for(int j = 0; j < 3; ++j) {
                for(int i = 2; i >= 0; --i) {
                    front[a][b] = temp[i][j];
                    b++;
                    if(b == 3) {
                        a++;
                        b = 0;
                    }
                }
            }

            char temp2[3];
            for(int i = 0; i < 3; ++i) {
                temp2[i] = up[2][i];
            }

            for(int i = 0; i < 3; ++i) {
                up[2][i] = lef[2-i][2];
                lef[2-i][2] = down[0][2-i];
                down[0][2-i] = righ[i][0];
                righ[i][0] = temp2[i];
            }
        } else {
            int a = 0;
            int b = 0;
            for(int j = 2; j >= 0; --j) {
                for(int i = 0; i < 3; ++i) {
                    front[a][b] = temp[i][j];
                    b++;
                    if(b == 3) {
                        a++;
                        b = 0;
                    }
                }
            }

            char temp2[3];
            for(int i = 0; i < 3; ++i) {
                temp2[i] = up[2][i];
            }

            for(int i = 0; i < 3; ++i) {
                up[2][i] = righ[i][0];
                righ[i][0] = down[0][2-i];
                down[0][2-i] = lef[2-i][2];
                lef[2-i][2] = temp2[i];
            }
        }
    }
}


int main(void) {
    int t, tc = 0;
    cin >> t;

    while(++tc <= t) {
        cin >> n;

        char oper;
        char direc;
        char temp[3];

        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                up[i][j] = 'w';
                down[i][j] = 'y';
                front[i][j] = 'r';
                back[i][j] = 'o';
                lef[i][j] = 'g';
                righ[i][j] = 'b';
            }
        }
        for(int i = 0; i < n; ++i) {
            cin >> temp;
            oper = temp[0];
            direc = temp[1];
            operation(oper, direc);
        }

        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                cout << up[i][j];
            }
            cout << endl;
        }
    }

}
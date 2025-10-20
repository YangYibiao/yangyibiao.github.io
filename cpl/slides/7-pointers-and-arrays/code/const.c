/************************
 * about const
 * @param p
 */
void fci(const int *p)
{
    int j;
    *p = 0; /*** 错误 ***/
    p = &j; /*** 合法 ***/
}

void fca(int * const p)
{
    int j;
    *p = 0;
    p = &j;
}

void fcia(const int * const p)
{
    int j;
    *p = 0;
    p = &j;
}

int main(void)
{
  return 0;
}
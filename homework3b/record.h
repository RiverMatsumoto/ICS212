struct record
{
    int             accountno;
    char            name[30];
    char            address[60];
    struct record*  next;
};

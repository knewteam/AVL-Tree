void in_order(node *aroot)
{
    if (aroot != NULL)
    {
        in_order(aroot->left);

        printf("\n%i", aroot->number);

        in_order(aroot->rigth);
    }
}

void pre_order(node *aroot)
{
    if (aroot != NULL)
    {
        printf("\n%i", aroot->number);

        pre_order(aroot->left);

        pre_order(aroot->rigth);
    }
}

void post_order(node *aroot)
{
    if (aroot != NULL)
    {
        post_order(aroot->left);

        post_order(aroot->rigth);

        printf("\n%i", aroot->number);
    }
}
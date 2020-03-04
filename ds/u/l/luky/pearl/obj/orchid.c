// An example book

inherit ITEM;

int query_autoload()
{return 1;
}
void create()
{
set_name("[1;32mÄõªá[0m",({"orchid"}));
set_weight(1250);
set("unit","®è");

	set("long",
"³o¬O¤@®èÄõªá,Å¥»¡¬O»s³yÄõ¥dÃÄ¤ôªº§÷®Æ\n"
		);
set("supply",1);
set("value",125);
}

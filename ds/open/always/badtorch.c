// An example book
inherit ITEM;
void create()
{
set_name("燒完的火把",({"torch","badtorch"}));
set_weight(100);
set("value",0);
set("unit","隻");
set("long","一支燒完的火把。\n");
setup();
}

int do_use(object me,string arg)
{
      tell_object(me,"這個火把已經燒完了!\n");	
      return 1;
}

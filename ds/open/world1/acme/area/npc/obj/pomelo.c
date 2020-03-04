inherit ITEM;
void create()
{
       set_name("柚子", ({ "pomelo" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "這是一顆水果，外層包著一層厚厚的果皮，你能剝下(denude)它。\n");
                set("unit", "個");
                set("value",400);
        }
     setup();
}
void init()
{ 
         add_action("do_denude","denude");
}
int do_denude(string arg)
{
          object me,furit,peel,obj;
          me=this_player();
          obj=this_object();
          if(arg != "pomelo") return notify_fail("你要剝什麼？\n");
          else {
            message_vision("$N使勁的剝著柚子皮。\n",me);
            furit=new(__DIR__"furit");
            peel=new(__DIR__"peel");
furit->move(me);
peel->move(me);
            destruct(obj);
            return 1;
          }
}

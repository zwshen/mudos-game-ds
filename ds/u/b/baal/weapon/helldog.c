#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIR"地獄犬"NOR,({"hell dog","dog"}));
        set("long","這是索思的座騎─地獄犬。\n");
        set("race","野獸");
        set_weight(30000);

        set("limbs", ({ "頭部","身體","前腳","後腳","頭部" }));
        set("verbs", ({ "bite","claw","crash" }));

        set("level",80);
        set("age",450);

        set_temp("apply/damage",750);
        set_temp("apply/armor", 1500);

        set("no_get",1);
        set("no_drop",1);
        set("amount",1);
        set("ridable",1);

        set("chat_chance",1);
        set("chat_msg",({
  (: command("dog") :),
  this_object()->name()+"在路上跑了跑。\n",
  (: command("cow") :),
  (: command("jump") :),
  (: command(":D") :),
  (: command(":)") :),
  (: command(":P") :),
}));
        set("unit","隻");
    set("value",0);
        set("member0","none");
        set("member1","none");
        set("member2","none");
        setup();
}

void init()
{
        ::init(); //luky
        add_action("do_name","name");
        if(environment(this_object())==this_player())
        {
          add_action("do_member","member");
          add_action("do_run","run");
        }
}

int ride_before_action(object me)
{
        object ob=this_object();
        message_vision("$N輕輕一躍，坐上"+this_object()->name()+"。\n",me);
        //me->set_temp("apply/short",({ me->short()+HIY"< 正騎著"NOR+this_object()->name()+HIY" >"NOR}));
        return 1;
}

int ride_after_action(object me)
{
        message_vision("$N穩穩的坐在"+this_object()->name()+"上面了。\n",me);
        //this_object()->set_weight(10);
        //this_object()->move(me);
        set("chat_chance",0);
        return 1;
}

int ride_off_action(object me)
{
        message_vision("$N從"+this_object()->name()+"的背上跳了下來。\n",me);
        message_vision("$N忘了所有的記憶了！！\n",this_object());
        this_object()->set("member0","none");
        this_object()->set("member1","none");
        this_object()->set("member2","none");
        set("chat_chance",1);
        //me->delete_temp("apply/short");
        return 1;
}

int do_member(string arg)
{
        int n_save;
        string where;
        object me,env;
        me=this_player();
        if(! env = environment(me)) return 0;
        if( !arg || sscanf(arg,"here at %d",n_save)!=1 )
                return notify_fail("指令格式: member here at <第幾個記億>. \n");
        if( n_save > 3 || n_save < 1)
                return notify_fail("地獄犬恐怕沒你記得那麼多吧...。\n");
        n_save -= 1;
        where=(string)file_name(env);
        message_vision("$N命令地獄犬記住這個地方。\n",me);
        set("member"+n_save, where+".c");
        return 1;
}

int do_run(string str)
{
        int n_save;
        string arg;
        object me=this_player();
        if(!me) return 0;
   if(me->query_temp("killer"))
  {
    write("你殺了人暫時不可以使用此令!\n");
    return 1;
  }
   if(me->query_temp("invader"))
  {
    write("你攻擊了玩家暫時不可以使用此指令!\n");
    return 1;
  }

    if( me->is_busy() || me->is_block() || me->is_fighting()) return notify_fail("你上一個動作還沒完成。\n");
        if( sizeof(me->query_temp("is_busy")) ) return notify_fail("你上一個動作還沒完成。\n");
        if( !me->query_temp("ride") )
                return notify_fail("你並沒有騎著地獄犬。\n");
        if( me->query_temp("horse_run") )
                return notify_fail("你正在騎著地獄犬往某地前進中喔。\n");
        if( !str || sscanf(str,"at %d",n_save)!=1 )
                return notify_fail("指令格式: run at <地獄犬的第幾個記憶>. \n");
        if( n_save > 3 || n_save < 1 )
                        return notify_fail("沒這個記憶喔....。\n");
        n_save -= 1;
        arg = this_object()->query("member"+n_save);
        if( arg=="none" || !arg ) 
                return notify_fail("你好像沒有叫牠記住什麼，所以牠並沒有什麼反應。\n");
        if( arg==(string)file_name(environment(me))+".c" )
                return notify_fail("你不就在這裡了？\n");
        tell_room(environment(me),me->name()+"騎著他的"+this_object()->name()+"往別的方向而去。\n",({ me }));
        me->move(__DIR__"obj/runwait.c");
        tell_object(me,"你開始往某地前進．．．\n");
        me->start_busy(10);
        me->set_temp("horse_run",1);
        call_out("for_go",3,me,this_object(),arg);
        call_out("for_go1",10,me,this_object(),arg);
        call_out("for_go2",13,me,this_object(),arg);
        return 1;
}

void for_go(object me,object ob,string where)
{
        object go_room;
        go_room = load_object(where);
        message_vision(HIY"$N騎著$n緩慢的往"+go_room->query("short")+"前進去．．．．．\n"NOR,me,ob);
        return;
}

void for_go1(object me,object ob,string where)
{
        object go_room;
        go_room = load_object(where);
        message_vision(HIC"慢慢的，$N已快到達了目的地了．．．．．．\n"NOR,me);
        return;
}

void for_go2(object me,object ob,string where)
{
        me->move(where);
        tell_object(me,HIR"你到達了目的地了！∼∼\n"NOR);
        tell_room(environment(me),me->name()+"突然從一個地方騎著他的"+ob->name()+"來到了這裡。\n",({ me }));

        ob->move(me);
        me->delete_temp("horse_run");
        return;
}

int do_name(string arg)
{
        string n_who,name;
        object me,object_h;
        me = this_player();
        if(!arg || sscanf(arg,"%s as %s",n_who,name )!=2 )
                return notify_fail("格式： name <那隻地獄犬> as <名字> .\n");
        if( !present(n_who,environment(me)) )
                return notify_fail("沒有這個地獄犬. \n");
        if( !objectp(object_h=present(n_who,environment(me))) )
                return notify_fail("格式： name <那隻地獄犬> as <名字> .\n");
        if( object_h->query("id") != this_object()->query("id") )
                return notify_fail("格式： name <那隻地獄犬> as <名字> .\n");
                arg = replace_string(arg, "$BLK$", BLK);
        name = replace_string(name, "$RED$", RED);
        name = replace_string(name, "$GRN$", GRN);
        name = replace_string(name, "$YEL$", YEL);
        name = replace_string(name, "$BLU$", BLU);
        name = replace_string(name, "$MAG$", MAG);
        name = replace_string(name, "$CYN$", CYN);
        name = replace_string(name, "$WHT$", WHT);
        name = replace_string(name, "$HIR$", HIR);
        name = replace_string(name, "$HIG$", HIG);
        name = replace_string(name, "$HIY$", HIY);
        name = replace_string(name, "$HIB$", HIB);
        name = replace_string(name, "$HIM$", HIM);
        name = replace_string(name, "$HIC$", HIC);
        name = replace_string(name, "$HIW$", HIW);
        name = replace_string(name, "$NOR$", NOR);

        message_vision("$N把$n的名字改為【"+name+"】\n"NOR,me,this_object());
        this_object()->set("name",HIW"疾電"NOR+"【"+name+NOR"】");
        return 1;
}

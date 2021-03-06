#include <ansi.h>
#include <path.h>

inherit NPC;
inherit SELLMAN;
int sort_user(object ob1, object ob2);
void open_war(int x);
void end_war();

void create()
{
        set_name("不知名的大白鬍老人",({"unknow oldman","oldman","man"}) );
        set("long",@LONG
一個不知其姓名的老先生，看不出多大年紀，留著一大把白鬍子，滿
臉紅通通的甚是溫和，身著大紅色的大衣，樣式奇特，不是這時代的衣著
，背上負著一個大紅色的袋子，看起來鼓鼓的，不知裝了啥玩意。他發現
你正看著他，隨既對著你呵呵的笑著。
LONG
);
        set("age",1200);
        set("level",1);
        set("attitude", "peaceful");
        set("race","人類");
        set("gender", "男性" );
        set("chat_chance",10);
        set("chat_msg",({
        (:command("sing 叮叮噹∼叮叮噹∼鈴聲多響亮∼∼"):),
        "老人呵呵的笑了起來，似乎非常高興。\n",
        "老人喃喃自語說道：「一年難得下來一次，卻是下來捉捕走散的雞群們。」\n",
        (:command("say 雪花紛紛何所似？"):),
        }) );
        set("sell_list",([
                __DIR__"net" : 10       ,
        ]) );
        setup();
}


void open_war(int x)
{
        int mark_loaded;
        int i, j, w;
        string dir;
        mixed *file;
        object ob,c,p;
        ob=this_object();
//        if( ob->query("open_war")==1 ) return;
        switch (x)
        {
        case 1:         //滄縣
        command("scream");
        message("world:world1:vision",
HIY "\n\t風添雪冷 雪趁風威 紛紛柳絮狂飄 片片鵝毛亂舞\n\n" NOR
HIW "【聖誕之音】滄縣、天城、步靈城等各地忽聞雞聲四起！！\n\n"NOR
CYN "(聖誕火雞大暴走！！)\n" NOR
        ,users() );
               return; // By Tmr
        dir = resolve_path("/open/world1/tmr/area/", "");
        if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";
        file = get_dir(dir, -1);
        if( !sizeof(file) ) return;
        i = sizeof(file);
        w = 0;
        while(i--) {
                if (file[i][1]==-2) file[i][0] += "/";
                if (strlen(file[i][0])>w) w = strlen(file[i][0]) + 1;
        }
        while (i<33)
        {
                j=random(sizeof(file) );
                  if (strsrch(file[j][0], "/") < 0 && stringp(file[j][0]) ) 
                {
                i++;
                c=new(__DIR__"chicken");
                c->move(TMR_PAST+"area/"+file[j][0] );
                }
        }
        call_out("open_war",10,x+1);

        break;
        case 2:         //天城
        dir = resolve_path("/open/world1/acme/area/", "");
        if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";
        file = get_dir(dir, -1);
        if( !sizeof(file) ) return;
        i = sizeof(file);
        w = 0;
        while(i--) {
                if (file[i][1]==-2) file[i][0] += "/";
                if (strlen(file[i][0])>w) w = strlen(file[i][0]) + 1;
        }
        while (i<33     )
        {
                j=random(sizeof(file) );
                  if (strsrch(file[j][0], "/") < 0 && stringp(file[j][0]) ) 
                {
                i++;
                c=new(__DIR__"chicken");
                c->move(ACME_PAST+"area/"+file[j][0] );
                }
        }
        call_out("open_war",10,x+1);
        break;

        case 3:         //步靈城
        dir = resolve_path("/open/world1/cominging/area/", "");
        if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";
        file = get_dir(dir, -1);
        if( !sizeof(file) ) return;
        i = sizeof(file);
        w = 0;
        while(i--) {
                if (file[i][1]==-2) file[i][0] += "/";
                if (strlen(file[i][0])>w) w = strlen(file[i][0]) + 1;
        }
        while (i<33)
        {
                j=random(sizeof(file) );
                  if (strsrch(file[j][0], "/") < 0 && stringp(file[j][0]) ) 
                {
                i++;
                c=new(__DIR__"chicken");
                c->move(COMINGING_PAST+"area/"+file[j][0] );
                }
        }
        break;
        }
        return;
}

void end_war()
{
        object chicken,ob;
        ob=this_object();

        if(ob->query("open_war")!=1) return;
        if(objectp(chicken=find_living("Merry_Xmas_chicken") ) )
        {
                if(!environment(chicken)) destruct(chicken);
                call_out("end_war",60);
        }
        else {
message("world:world1:vision",HIY "\n\n聖誕老人快樂的唱道：我的雞∼我的雞∼∼已經全捉到了。\n\n" NOR,users() );
                ob->set("open_war",0);
        }       
        return;
}

void init()
{
        ::init();
        add_action("do_change","change");
         add_action("do_list","llist");
          add_action("do_buy","bbuy");
       add_action("do_speak","speak");
      add_action("do_gamelist","gamelist");
}

int do_speak(string arg)
{
        object me,ob;
        me=this_player();
        ob=this_object();
        if(!arg || arg!="祝大家聖誕節快樂" ) return 0;

           message_vision(HIG "$N高聲說道：「祝大家聖誕節快樂！！」\n" NOR,me);

        if (this_object()->query("open_war")==1 )  
        {
             message_vision(HIR"$N說道：火雞還沒捉完吧，加油！！加油！！\n"NOR,ob);
             call_out("end_war",1);
        }
        else {
             ob->set("open_war",1);
             call_out("open_war",1,1);
        }
        return 1;
}

int do_change(string arg)
{
        int i;
        object me,p;

        me=this_player();
        i=me->query("Merry_Xmas/chicken");

        if(!arg) return notify_fail("你想兌換什麼獎品？(exp)(pill)(popularity)\n");
        switch (arg)
        {
        case "exp":
        message_vision("$N想兌換經驗值。\n",me);
        if (i<1) return notify_fail("你無法兌換經驗值。\n");
        message_vision(HIY "$N從背後的大紅色袋子拿出個「500 exp」送給了$n。\n" NOR ,this_object(),me );
        me->add("exp",500);
        me->add("Merry_Xmas/chicken",-1);       
        break;

        case "pill":
        message_vision("$N想兌換聖誕藥丸。\n",me);
        if (i<5) return notify_fail("你無法兌換聖誕藥丸。\n");
        p=new(__DIR__"xmaspill");
        p->move(me);
        message_vision(HIY "$N從背後的大紅色袋子拿出顆丹藥送給了$n。\n" NOR ,this_object(),me );
        me->add("Merry_Xmas/chicken",-5);
        break;

        case "popularity":
        message_vision("$N想兌換聲望。\n",me);
        if (i<10) return notify_fail("你無法兌換聲望。\n");
        message_vision(HIY "$N從背後的大紅色袋子拿出一點聲望送給了$n。\n" NOR ,this_object(),me );
        me->add("popularity",1);
        me->add("Merry_Xmas/chicken",-10);
        break;

        default:
        return notify_fail("沒有這種獎品能夠兌換。\n");
        break;
        }
        return 1;
}

int do_gamelist()
{
        string str, *option;
        object *list,me;
        int i, j, ppl_cnt,opt_id;
        
        me=this_player();
        str = HIW "◎  聖誕火雞大暴走線上排名 \n" NOR;
        str += "─────────────────────────────────────\n";
        list = users();
        list = sort_array(users(), "sort_user", this_object());
                ppl_cnt = 1;
                j = sizeof(list);
                while( j-- ) {
                        // Skip those users in login limbo.
                        if( !environment(list[j]) ) continue;
                        if(!list[j]->query("Merry_Xmas/chicken") ) continue;
                        if( me && !list[j]->visible(me) ) continue;             
          str = sprintf("%s%-30s%s",
           str,
              "第"+(string)ppl_cnt+"名："+list[j]->query("name"),
              (string)list[j]->query("Merry_Xmas/chicken")+"隻。\n",
           );
                        ppl_cnt++;
                }
                
        str += "─────────────────────────────────────\n";
        me->start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
        int ord;

        ord = ob1->query("Merry_Xmas/chicken")-ob2->query("Merry_Xmas/chicken");
        if( ord==0 )
                ord = (int)ob1->query_level() - (int)ob2->query_level();
        return ord;
}




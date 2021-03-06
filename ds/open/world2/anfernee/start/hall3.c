// 更新日期: 2003.06.13	修改人: Shengsan@ms2.url.com.tw 修改代號: sV1
#include <path.h>
#include <ansi.h>
#include <command.h>
inherit ROOM;

void create()
{
      set("short", HIY"未之夢房"NOR);
    set("long",@long
你來到一間四面都是白色牆壁的房間，房間地上鋪的是一層七彩的毛
毯，光著腳丫子踩在上頭真是舒服極了。房間中央竟然擺著一張透明的床
（ｂｅｄ），令人驚奇的是這張床是沒有床腳撐著，也沒有繩子吊著，就
漂浮般的在半空中「卡」著，不由得令人覺得十分訝異。
long
	);

	set("exits", ([ /* sizeof() == 1 */
      "south" : __DIR__"hall2",
	]) );
	set("item_desc", ([
          "bed": "一張長形而漂浮在半空的軟床, 供休息(sleep on bed)之用。\n",
	]) );
	set("light",1);
	set("no_clean_up", 0);
	set("no_fight",1);
	set("no_kill",1);
	setup();
}

void init()
{
        add_action("do_sleep","sleep");
}

int do_sleep(string arg)
{
 object me,*inv;
 int i;
 string buffer1,file,name;
 me=this_player();
 if(!arg) return 0;
	write("未來整修中,暫時關閉. -by alickyuen-\n");
	return 1;
 if(me->query_temp("ride"))
 {
 	write(" 你騎著東西怎麼睡??\n");
 	return 1;
 }
 if(me->is_ghost())
 {
 	write(HIW"  正當你要上床時, 一股悠悠的聲音傳來:  鬼是不需要睡覺的。\n"NOR);
 	return 1;
 }
 if(me->is_busy())
 {
 	write("你上一個動作還沒完成。\n");
 	return 1;
 }
 if(sscanf(arg, "on %s", arg)==1)
 {
  if(arg=="bed")
  {
   if(name=this_object()->query_temp("on_use"))
   {
   	if(name == me->query("name")) write("你已經在床上睡覺了。\n"NOR);
   	else write(HIW"正當你要上床時,"+name+"立刻一腳把你踢到床下。\n"NOR);
   	return 1;
   }
   /* sV1 轉換時空改為不丟掉物品
   inv = all_inventory(me);
   for(i=0; i<sizeof(inv); i++)
   {
    if(inv[i]->query("secured")) inv[i]->delete("secured");
    if(!inv[i]->query("base_value"))
    {
     file=base_name(inv[i]);
     if(sscanf(file,"/open/world2/%s",buffer1)!=1
     && sscanf(file,"/open/always/%s",buffer1)!=1 )
     {
      if(inv[i]->query("equipped")) inv[i]->unequip();
      DROP_CMD->do_drop(me, inv[i]);
     }
    }
   }
   轉換時空改為不丟掉物品 sV1 */
   this_object()->set_temp("on_use",me->name());
   call_out("empty",8);
   me->disable_player(" <熟睡中>");
   tell_room(this_object(),me->name()+"爬上了床, 伸了個懶腰, 開始呼呼大睡了起來。\n",({ me }));
   //sV1 message("system", "你放下一些多餘的物品, 爬上了床, 伸了個懶腰, 開始呼呼大睡了起來。\n",me);
   message("system", "你爬上了床, 伸了個懶腰, 開始呼呼大睡了起來。\n",me);//sV1
   me->start_busy(5);
   call_out("step1",3,me);
   call_out("step2",8,me);
   call_out("step3",10,me);
   return 1;
  } 
 }
 else return 0;
}

void empty()
{
 this_object()->delete_temp("on_use");
}

void step1(object me)
{
 message("system", "\n你感覺身旁的聲音似乎越來越遠.. 意識越來越模糊..\n\n",me);
 me->set_temp("block_msg/all", 1);
 message_vision("床上的$N發出陣陣的打呼聲...\n",me);
}

void step2(object me)
{
 this_object()->delete_temp("on_use");
 message_vision("圓床周圍漸漸泛起一圈圈藍色的光環, 一陣閃爍之後, $N突然從床上消失了。\n",me);
    me->move(FUTURE"tmr/basic/hotel");
    me->set("startroom",FUTURE"tmr/basic/hotel");
 me->save();
 me->set_temp("block_msg/all", 0);
 message("system", "一陣寂靜之後, 你感覺周圍又漸漸熱鬧了起來。\n\n",me);
 me->set_temp("block_msg/all", 1);
 message_vision("一陣強光之後，$N睡眼惺忪的從地上站了起來。\n",me);
}

void step3(object me)
{
 me->revive(1);
 me->command("look");
}

#include <ansi.h>
inherit ROOM;
int valid_leave(object me, string dir);
int room_effect(object me);
mapping default_dirs = ([
        "north":                "北",
        "south":                "南",
        "east":                 "東",
        "west":                 "西",
        "northup":              "北邊",
        "southup":              "南邊",
        "eastup":               "東邊",
        "westup":               "西邊",
        "northdown":            "北邊",
        "southdown":            "南邊",
        "eastdown":             "東邊",
        "westdown":             "西邊",
        "northeast":            "東北",
        "northwest":            "西北",
        "southeast":            "東南",
        "southwest":            "西南",
        "up":                   "上",
        "down":                 "下",
        "enter":                "內",
        "out":                  "外",
        "exit":                 "出口",
]);
void setroom()
{
       set("no_clean_up",0);
       set("light",1);
       set("no_map",1);
       set("no_recall","這裡陰氣太重上天聽不到你呼喚的\n");
}  
int do_chgo(object me,string arg)
{ 
     mixed newexit;
     object env,ride;
     mapping exits;
     int i,invied=0; 
     string dir,*dirs,who,min,mout,no_go;
     env=environment(me);
     exits=env->query("exits");
     no_go=env->query("no_random_move");
     ride=me->query_temp("ride");
     dirs=keys(exits);
     dirs-=({no_go});
     dir=dirs[random(sizeof(dirs))];
     newexit=exits[dir];      
     who=me->name();
     if(ride) who=who+"騎著"+ride->name();
     if( !undefinedp(default_dirs[dir]) )
                        dir = default_dirs[dir];
                else
                        dir = dir;
     mout = "往" + dir + "離開。\n";
     if(me->query("race")=="human")
     min = "來到此地。\n";
     else min = "來到此處。\n";
     if(wizardp(me))
     message_vision(HIM"$N被幻境所迷惑了方向"+dir+"\n"NOR,me);   
     if(me->query_temp("invis") < 1 )
     {
                message( "vision", who + mout, environment(me), ({me}) );
     }
     else invied=1;
     me->move(newexit);
     if(!invied)
     {
       message("vision", who + min, environment(me), ({me}) );
       all_inventory(env)->follow_me(me, arg);
     }
     return 1;   
} 
int room_effect(object me)
{      
      int fantasy,fin,lin;
      fin=me->query_int()/15;
      lin=me->query_skill("literate",1)/23;
      if(!userp(me))  //玩家才會被打到
      return 0;
      if(fin+lin>=8)
         fantasy=8;          
      else if(fin+lin>=7)
         fantasy=7;
      else if(fin+lin>=6)
         fantasy=6;
      else if(fin+lin>=5)
         fantasy=5;
      else if(fin+lin>=4)
         fantasy=4;
      else if(fin+lin>=3)
         fantasy=3;
      else if(fin+lin>=2)
         fantasy=2;
      else   
         fantasy=1;
       if(fantasy>6)
        fantasy-=random(2);
       if(fantasy<3)
        fantasy+=random(2);
       if(random(2)) //機率再1/2..降低出現率
    switch(fantasy){
    case 8: message_vision(HIM"$N眼前忽然出現幻影,$N極快辨認出真假只有擦傷\n"NOR,me);
            me->receive_damage("hp",10+random(10));
            return 1;
    case 7: message_vision(HIM"$N被突然閃現的幻影攻擊,$N即時察覺只有一點傷\n"NOR,me);  
            me->receive_damage("hp",10+random(20));
            return 1;
    case 6: message_vision(HIM"眼前出現一片幻境,$N迅速發現破綻只有一些傷\n"NOR,me);
            me->receive_damage("hp",20+random(30));
            return 1;         
    case 5: message_vision(HIM"正前方幻影連綿不斷,$N及時警覺只有小傷\n"NOR,me);
            me->receive_damage("hp",25+random(30));
            return 1;         
    case 4: message_vision(HIM"$N身邊一時間幻象大作,$N發覺太晚受到創傷\n"NOR,me);
            me->receive_damage("hp",25+random(40));
            return 1;    
    case 3: message_vision(HIM"$N沒注意到身旁出現幻影,$N被幻影打傷了\n"NOR,me);
            me->receive_damage("hp",25+random(50));
            return 1;    
    case 2: message_vision(HIM"$N無法分別眼前幻境,$N受了嚴重傷害\n"NOR,me);
            me->receive_damage("hp",35+random(50));
            return 1;                  
    case 1: message_vision(HIM"$N因為一直被幻象欺騙攻擊,$N受了極大創傷\n"NOR,me);
            me->receive_damage("hp",45+random(50));
            return 1;   
    }       
}

int valid_leave(object me, string dir)
{
  object env,*inv;
  int i,fin,lit;
  env=environment(me);
  inv = all_inventory(env);
  fin = me->query_int()/2;  //智慧/2  
  lit = me->query_skill("literate",1)/7; //sk literate/7  
  for(i=0;i<sizeof(inv);i++)
   {
      if(living(inv[i]) && inv[i]->query("fong_guard")  )
      {
        if( inv[i]->is_corpse() ) continue;
        message_vision(HIW"$N衝了出來擋住你的去路\n"NOR,inv[i]);
        return notify_fail("");       
      }
   }  
   if(random(fin)*3/4 + lit + fin > 20 + random(60))
   {
     return ::valid_leave(me, dir);
   }
   else
   {
    do_chgo(me,dir);  //用這種方式是因為如果使用do_go...會讓玩家可以用alias x xxx             
    return 0;         //來逃過判定...不過很麻煩就是..-.-
   } 
}











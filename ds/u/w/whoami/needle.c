#include <weapon.h>
#include <ansi2.h>
inherit DAGGER; 
object ob2;
void create()
{
        set_name("銀針", ({ "silver needle","needle" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根"); 
                set("long", "這是一根行醫者必備的銀針，同時也是天梟教教眾們的信物•但\n"
                            "是知道其中秘密的，卻只有少部份的天梟弟子們•\n");
//                set("no_drop", 1);
//                set("no_give", 1);
//                set("no_sac", 1);
                }
        setup();
}

void init()
{
 if(this_player()!=environment(this_object())) return;
        add_action("do_help","help");
        add_action("do_acupuncture","acupuncture");
}

int do_acupuncture(string str)
{
        object ob1,me;
        string st1,st2,*limbs,limb,msg,*msgs,msg1;
     
int mywit,mydex,tdex,myint,tint,mylv,tlv,mysk,tdodge,mytec,ttec,maxhp,attackon,damage;

        me=this_player();
        mysk=me->query_spell("moxibustion");
        myint=me->query("int");
        mylv=me->query("level");
        mytec=me->query_Merits("tec");
        limbs = ({ "頭部","身體","手部","腳部" });
        msgs  = ({
HIC"\n    百花千草各有途\n"
   "                  熟知哪株療奇毒\n"NOR,
HIC"\n    為謀天下蒼生福\n"
   "                  孤嚐百草造浮屠\n"NOR,
HIC"\n    仙山靈藥長於險\n"
   "                  徒手攀藤為蒼生\n"NOR,
HIC"\n    峭壁懸崖信手攀\n"
   "                  不求得道登天壇\n"NOR,
HIC"\n    神農百草救天下\n"
   "                  佛祖泛音渡眾生\n"NOR,
HIC"\n    孤行千里上君山，為求仙山靈芝丸\n"
   "    清風野雁伴我遊，誰說其中無樂含\n"NOR,
HIC"\n    誤食毒草千萬回，幸得神仙洗經髓\n"+
   "    待孤以血譜醫訣，救得萬靈把命回\n"NOR,
                                });
 
       msg = msgs[random(sizeof(msgs))];

        if( me->query("class1") != "天梟教")
           return notify_fail("只有天梟教教徒才能使用炙穴針灸•\n");
        if( me->is_busy() )
           return notify_fail("你現在正在忙，無法使用炙穴針灸！\n"); 
        if( !present("needle",me) )
           return notify_fail("你必須找把針才能使用炙穴針灸•\n");
        if( me->query("hp") < 300 || me->query("ap") < 300 || me->query("mp") < 300
            || me->query("wound/left_arm") > 10 || me->query("wound/right_arm") >10 )
           return notify_fail("你現在身體狀況不佳無法使用炙穴針灸•\n"); 
        if (!str || str=="") 
           return notify_fail ("請用help needle查詢可用的功\能•\n");
        if (sscanf( str,"%s on %s",st1,st2)!=2 )
        return notify_fail ("acupuncture <ob1> on <ob2>\n");
           if (!ob2=present(st2,environment(this_player())))
              return notify_fail("找不到 "+st2+" 這個生物.\n");
           if(!ob2->is_character() || ob2->is_corpse())
              return notify_fail("你看清楚一點，那並不是活物。\n");

     switch( st1 ) {
       
       default:
          tell_object(me,"請用help needle查詢可用的功\能•\n");
        break;       

       case "rekee":

             if( me->is_fighting() )
              return notify_fail("打鬥中你哪有時間替"+ob2->query("name")+"針灸！\n");
             if ( me->query("level") < 15 )
              return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");
             if ( mysk < 5 )
              return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIC"療氣訣"NOR"》•\n");  
             if ( ob2->query("hp") >= ob2->query("max_hp") )
              return notify_fail(ob2->query("name")+"並沒有受傷•\n");
message_vision(
YEL"$N口中吟唱神農氏的薪傳詩歌\n"+NOR
YEL"\n           同時手中銀針也化為點點寒芒刺出！\n"NOR+
HIW"\n    ───《"HIY" 療 氣 訣"HIW" 》───\n"+NOR
+msg,me);
               me->start_busy(2-myint/50);  
               me->receive_damage("ap",mysk*2 - myint/2 ); 
     if ( (mysk + myint + mylv/5 ) >= random(25) ){
        msg1 = HIW"\n四周祥光籠罩，無數光影生氣在祥光中化為點點光球，附著在$N四周！！\n"NOR ;
        message_vision(msg1, ob2);
               ob2->receive_heal("hp",mysk*2); 
               me->improve_spell("moxibustion",random(myint/10));
     } else {
    ob2->receive_damage("mp",random(mysk));
    ob2->receive_damage("ap",random(mysk));
    if ( ob2 == me ){
    message_vision(HIB"\n$N一個分心，針插錯了穴位，$N痛得彎下腰來•\n"NOR,me);
    } else { 
    msg1 = HIB"\n$N一個分心，針就插錯了穴位，讓$n感到一陣昏厥•\n"NOR ;
    message_vision(msg1, me, ob2);
    }
}
        break;
      
      case "regin":      

           if( me->is_fighting() )
              return notify_fail("打鬥中你哪有時間替"+ob2->query("name")+"針灸！\n");
           if ( me->query("level") < 15 )
              return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");
           if ( mysk < 5 )
              return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIG"療精訣"NOR"》•\n");  
           if ( ob2->query("ap") >= ob2->query("max_ap") )
              return notify_fail(ob2->query("name")+"的內勁充沛•\n");
message_vision(
YEL"$N口中吟唱神農氏的薪傳詩歌\n"+NOR
YEL"\n           同時手中銀針也化為點點寒芒刺出！\n"NOR+
HIW"\n    ───《"HIG" 療 精 訣"HIW" 》───\n"+NOR
+msg,me);
                me->start_busy(2-myint/50); 
                me->receive_damage("mp",mysk*2 - myint/2); 
     if ( (mysk + myint + mylv/5 ) >= random(25) ) {
        msg1 = HIW"\n四周祥光籠罩，無數光影生氣在祥光中化為點點光球，附著在$N四周！！\n"NOR ;
        message_vision(msg1, ob2);
                ob2->receive_heal("ap",mysk*2); 
                me->improve_spell("moxibustion",random(myint/10));
     } else {
    ob2->receive_damage("mp",random(mysk));
    ob2->receive_damage("ap",random(mysk));
    if ( ob2 == me ){
    message_vision(HIB"\n$N一個分心，針插錯了穴位，$N痛得彎下腰來•\n"NOR,me);
    } else { 
    msg1 = HIB"\n$N一個分心，針就插錯了穴位，讓$n感到一陣昏厥•\n"NOR ;
    message_vision(msg1, me, ob2);
    }
}
        
      break; 

      case "resen":
   
           if( me->is_fighting() )
                return notify_fail("打鬥中你哪有時間替"+ob2->query("name")+"針灸！\n");
           if ( me->query("level") < 15 )
              return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");
           if ( mysk < 5 )
              return notify_fail("你對炙穴針灸不夠熟練，無法使出《"NOR+MAG"療神訣"NOR"》•\n");  
           if ( ob2->query("mp") >= ob2->query("max_mp") )
               return notify_fail(ob2->query("name")+"的魔力充沛•\n");
message_vision(
YEL"$N口中吟唱神農氏的薪傳詩歌\n"+NOR
YEL"\n           同時手中銀針也化為點點寒芒刺出！\n"NOR+
HIW"\n    ───《"NOR+MAG" 療 神 訣"HIW" 》───\n"+NOR  
+msg,me);
                me->start_busy(2-myint/50); 
                me->receive_damage("ap",mysk*2 - myint/2); 
      if ( (mysk + myint + mylv/5 ) >= random(25) ){
        msg1 = HIW"\n四周祥光籠罩，無數光影生氣在祥光中化為點點光球，附著在$N四周！！\n"NOR ;
        message_vision(msg1, ob2);
                ob2->receive_heal("mp",mysk*2); 
                me->improve_spell("moxibustion",random(myint/10));
                return 1;
     } else {
    ob2->receive_damage("mp",random(mysk));
    ob2->receive_damage("ap",random(mysk));
    if ( ob2 == me ){
    message_vision(HIB"\n$N一個分心，針插錯了穴位，$N痛得彎下腰來•\n"NOR,me);
    } else { 
    msg1 = HIB"\n$N一個分心，針就插錯了穴位，讓$n感到一陣昏厥•\n"NOR ;
    message_vision(msg1, me, ob2);
    }
}
      break; 
     case "advkee":
          if( me->is_fighting() )
               return notify_fail("打鬥中你哪有時間替"+ob2->query("name")+"針灸！\n");
          if ( me->query("level") < 20 )
               return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");
          if ( mysk < 20 )
               return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIC"善世訣"NOR"》•\n");  
          if ( ob2->query("hp") >= ob2->query("max_hp") )
               return notify_fail(ob2->query("name")+"並沒有受傷•\n");
message_vision(
YEL"$N口中吟唱神農氏的薪傳詩歌\n"+NOR
YEL"\n           同時手中銀針也化為點點寒芒刺出！\n"NOR+
HIW"\n    ───《"HIC" 善 世 訣"HIW" 》───\n"+NOR
+msg,me);
                me->start_busy(3-myint/50); 
                me->receive_damage("ap",mysk*2 - myint/4); 
    if ( (mysk + myint + mylv/5 ) >= random(50) ){
        msg1 = HIW"\n四周祥光籠罩，無數光影生氣在祥光中化為點點光球，附著在$N四周！！\n"NOR ;
        message_vision(msg1, ob2);
                ob2->receive_heal("hp",mysk*2+myint); 
                me->improve_spell("moxibustion",random(myint/10));
    return 1;
     } else {
    ob2->receive_damage("mp",random(mysk));
    ob2->receive_damage("ap",random(mysk));
    if ( ob2 == me ){
    message_vision(HIB"\n$N一個分心，針插錯了穴位，$N痛得彎下腰來•\n"NOR,me);
    } else { 
    msg1 = HIB"\n$N一個分心，針就插錯了穴位，讓$n感到一陣昏厥•\n"NOR ;
    message_vision(msg1, me, ob2);
    }
}
      break; 

     case "sky":
          if( me->is_fighting() )
               return notify_fail("打鬥中你哪有時間替"+ob2->query("name")+"針灸！\n");        
          if ( me->query("level") < 20 )
               return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");
          if ( mysk < 20 )
               return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIR"開天訣"NOR"》•\n");  
          if ( ob2->query("hp") >= ob2->query("max_hp") )
               return notify_fail(ob2->query("name")+"並沒有受傷•\n");
          if ( ob2->query("ap") >= ob2->query("max_ap") )
               return notify_fail(ob2->query("name")+"的內勁充沛•\n");
message_vision(
YEL"$N口中吟唱神農氏的薪傳詩歌\n"+NOR
YEL"\n           同時手中銀針也化為點點寒芒刺出！\n"NOR+
HIW"\n    ───《"HIR" 開 天 訣"HIW" 》───\n"+NOR
+msg,me);
                me->start_busy(3-myint/50); 
                me->receive_damage("mp",mysk*2 - myint/4 + mylv); 
if ( (mysk + myint + mylv/5 ) >= random(50) ){
        msg1 = HIW"\n四周祥光籠罩，無數光影生氣在祥光中化為點點光球，附著在$N四周！！\n"NOR ;
        message_vision(msg1, ob2);
                ob2->receive_heal("hp",mysk*2+myint+mylv); // 回復HP
                ob2->receive_heal("ap",mysk*2+myint+mylv); // 回復AP
                me->improve_spell("moxibustion",random(myint/10));
                return 1;
} else {
    ob2->receive_damage("mp",random(mysk));
    ob2->receive_damage("ap",random(mysk));
    if ( ob2 == me ){
    message_vision(HIB"\n$N一個分心，針插錯了穴位，$N痛得彎下腰來•\n"NOR,me);
    } else { 
    msg1 = HIB"\n$N一個分心，針就插錯了穴位，讓$n感到一陣昏厥•\n"NOR ;
    message_vision(msg1, me, ob2);
    }
}
      break; 
     case "heal":
          if( me->is_fighting() )
               return notify_fail("打鬥中你哪有時間替"+ob2->query("name")+"針灸！\n");
          if ( me->query("level") < 20 )
               return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");
          if ( mysk < 30 )
               return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIC"癒民訣"NOR"》•\n");  
message_vision(
YEL"$N口中吟唱神農氏的薪傳詩歌\n"+NOR
YEL"\n           同時手中銀針也化為點點寒芒刺出！\n"NOR+
HIW"\n    ───《"HIC" 癒 民 訣"HIW" 》───\n"+NOR
+msg,me);
               me->receive_damage("mp",mysk/4);
               me->start_busy(2-myint/50);
if ( (mysk + myint + mylv/5 ) >= random(70) ){
        msg1 = HIW"\n四周祥光籠罩，無數光影生氣在祥光中化為點點光球，附著在$N四周！！\n"NOR ;
        message_vision(msg1, ob2);
                ob2->receive_curing("all",mysk/10+myint/20); 
                me->improve_spell("moxibustion",random(myint/10));
        return 1;
} else {
    ob2->receive_damage("mp",random(mysk));
    ob2->receive_damage("ap",random(mysk));
    if ( ob2 == me ){
    message_vision(HIB"\n$N一個分心，針插錯了穴位，$N痛得彎下腰來•\n"NOR,me);
    } else { 
    msg1 = HIB"\n$N一個分心，針就插錯了穴位，讓$n感到一陣昏厥•\n"NOR ;
    message_vision(msg1, me, ob2);
    }
}
      break;
     case "addint": 
     if( me->is_fighting() )
        return notify_fail("打鬥中你哪有時間替"+ob2->query("name")+"針灸！\n");     
     if ( me->query("level") < 27 )
        return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");        
     if ( mysk < 50 )
        return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIW+BLK"陰心訣"NOR"》•\n");  
     if ( ob2->query("int") < 30 || ob2->query("level") < 27){
        tell_object(me,ob2->query("name")+"的體質無法承受《"HIW+BLK"陰心訣"NOR"》•\n");
        return 1;
        }
     if ( ob2->query_temp("e_int") >= 1 ){
         tell_object(me,ob2->query("name")+"已經接受過《"HIW+BLK"陰心訣"NOR"》了•\n");
     } else {
message_vision(
YEL"$N口中吟唱神農氏的薪傳詩歌\n"+
   "\n           同時手中銀針也化為點點寒芒刺出！\n"+NOR
HIW"\n    ───《"BLK" 陰 心 訣"HIW" 》───\n"+NOR                   
+msg,me);
         me->receive_damage("mp",mysk*2-myint/5);
         me->receive_damage("ap",mysk*2-myint/5);
         me->start_busy(3);
         ob2->start_busy(1);
         call_out("enhance",2,me);
         if ( (random(mysk) + random(myint) + mylv/5 ) >= random(110) ){
         ob2->add_temp("e_int",1);
         me->improve_spell("moxibustion",random(myint/10));
         }
         return 1;
     }
      break;
     case "addcon":
     if( me->is_fighting() )
        return notify_fail("打鬥中你哪有時間替"+ob2->query("name")+"針灸！\n");     
     if ( me->query("level") < 28 )
        return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");        
     if ( mysk < 50 )
        return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIG"三焦訣"NOR"》•\n");  
     if ( ob2->query("con") < 30 || ob2->query("level") < 28 ){
        tell_object(me,ob2->query("name")+"的體質無法承受《"HIG"三焦訣"NOR"》•\n");
        return 1;
        }
     if ( ob2->query_temp("e_con") >= 1 ){
         tell_object(me,ob2->query("name")+"已經接受過《"HIG"三焦訣"NOR"》了•\n");
     } else {
message_vision(
YEL"$N口中吟唱神農氏的薪傳詩歌\n"+ 
   "\n           同時手中銀針也化為點點寒芒刺出！\n"+NOR
HIW"\n    ───《"HIG" 三 焦 訣 "HIW"》───\n"+NOR               
+msg,me);
         if ( (random(mysk) + random(myint) + mylv/5 ) >= random(120) ){
         ob2->add_temp("e_con",1);
         me->improve_spell("moxibustion",random(myint/10));
         }
         call_out("enhance",2,me);
         me->receive_damage("mp",mysk*2-myint/5);
         me->receive_damage("ap",mysk*2-myint/5);
         me->start_busy(3);
         ob2->start_busy(1);
         return 1;
     }
      break;
     case "adddex":
     if( me->is_fighting() )
        return notify_fail("打鬥中你哪有時間替"+ob2->query("name")+"針灸！\n");     
     if ( me->query("level") < 29 )
        return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");        
     if ( mysk < 50 )
        return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIW"逸飄訣"NOR"》•\n");  
     if ( ob2->query("dex") < 30 || ob2->query("level") < 29 ){
        tell_object(me,ob2->query("name")+"的體質無法承受《"HIW"逸飄訣"NOR"》•\n");
        return 1;
        }
     if ( ob2->query_temp("e_dex") >= 1 ){
         tell_object(me,ob2->query("name")+"已經接受過《"HIW"逸飄訣"NOR"》了•\n");
     } else {
message_vision(
YEL"$N口中吟唱神農氏的薪傳詩歌\n"+
   "\n           同時手中銀針也化為點點寒芒刺出！\n"+
HIW"\n    ───《 逸 飄 訣 》───\n"+NOR           
+msg,me);
         if ( (random(mysk) + random(myint) + mylv/5 ) >= random(130) ){
         ob2->add_temp("e_dex",1);
         me->improve_spell("moxibustion",random(myint/10));
         }
         call_out("enhance",2,me);
         me->receive_damage("mp",mysk*2-myint/5);
         me->receive_damage("ap",mysk*2-myint/5);
         me->start_busy(3);
         ob2->start_busy(1);
         return 1;
     }
      break;
     case "addstr":
     if( me->is_fighting() )
        return notify_fail("打鬥中你哪有時間替"+ob2->query("name")+"針灸！\n");     
     if ( me->query("level") < 30 )
        return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");        
     if ( mysk < 50 )
        return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIY"太陽訣"NOR"》•\n");  
     if ( ob2->query("str") < 30 || ob2->query("level") < 30 ){
        tell_object(me,ob2->query("name")+"的體質無法承受《"HIY"太陽訣"NOR"》•\n");
        return 1;
        }
     if ( ob2->query_temp("e_str") >= 1 ){
         tell_object(me,ob2->query("name")+"已經接受過《"HIY"太陽訣"NOR"》了•\n");
     } else {
message_vision(
YEL"$N口中吟唱神農氏的薪傳詩歌\n"+ 
   "\n           同時手中銀針也化為點點寒芒刺出！\n"+
HIW"\n    ───《"HIY" 太 陽 訣"HIW" 》───\n"+NOR                 
+msg,me);
         if ( (random(mysk) + random(myint) + mylv/5 ) >= random(140) ){
         ob2->add_temp("e_str",1);
         me->improve_spell("moxibustion",random(myint/10));
         }
         call_out("enhance",2,me);
         me->receive_damage("mp",mysk*2-myint/5);
         me->receive_damage("ap",mysk*2-myint/5);
         me->start_busy(3);
         ob2->start_busy(1);
         return 1;
     }
      break;
     case "god":
     if( me->is_fighting() )
        return notify_fail("打鬥中你哪有時間替"+ob2->query("name")+"針灸！\n");     
     if ( me->query("level") < 35 )
        return notify_fail("你的經驗不足不能擅自替他人針炙•\n");
     if ( mysk < 65 )
        return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HBCYN+HIR"神憔氣血訣"NOR"》•\n"); message_vision(
   "$N頓時領悟神農扛籃覓藥嚐百草的辛勞，頓時有如神農降臨\n"+
   "   　　。。隨手揮出，式式自然，招招天成。。\n"+
HIW"\n    ───《"HBCYN+HIR" 神 憔 氣 血 訣"NOR+HIW" 》───\n"+NOR
+msg,me);

      me->start_busy(3-mysk/100-myint/100);
      me->receive_damage("mp",mysk*5);
if ( (mysk + myint + mylv/5 ) >= random(70) ){
        msg1 = HIW"\n四周祥光籠罩，無數光影生氣在祥光中化為點點光球，附著在$N四周！！\n"NOR ;
        message_vision(msg1, ob2);
    if( ob2->query_condition("poison") > 1){
    ob2->apply_condition("poison", ob2->query_condition("poison")-(mysk/10+myint/20) );
    tell_object(ob2,HIW"\n你感覺一陣涼爽，看來體內的毒性降低不少•\n"NOR);
    } else {
    ob2->apply_condition("poison", 0);
    }
    if( ob2->query_condition("blooding") > 1){
    ob2->apply_condition("blooding", ob2->query_condition("blooding")-(mysk/10+myint/20) );
    tell_object(ob2,HIW"\n你感覺你傷口處的血流慢慢的止住了•\n"NOR);
    } else {
    ob2->apply_condition("blooding", 0);
    }
    if( ob2->query_condition("whip_gas") > 1){
    ob2->apply_condition("whip_gas", ob2->query_condition("whip_gas")-(mysk/10+myint/20) );
    tell_object(ob2,HIW"\n你感覺體內的黃金氣勁被壓制了下來•\n"NOR);
    } else {
    ob2->apply_condition("whip_gas", 0);
    }
    if( ob2->query_condition("six_open_force") > 1){
    ob2->apply_condition("six_open_force",             ob2->query_condition("six_open_force")-(mysk/10+myint/20) );
    tell_object(ob2,HIW"\n你感覺體內的氣勁被壓制了下來•\n"NOR);
    } else {
    ob2->apply_condition("six_open_force", 0);
    } 
    if( ob2->query_condition("five-thunder") > 1){
    ob2->apply_condition("five-thunder", ob2->query_condition("five-thunder")-(mysk/10+myint/20) );
    tell_object(ob2,"\n");
    } 
      ob2->receive_heal("hp",maxhp);
      me->improve_spell("moxibustion",random(myint/10));
    return 1;
} else {
    ob2->receive_damage("mp",random(mysk));
    ob2->receive_damage("ap",random(mysk));
    if ( ob2 == me ){
    message_vision(HIB"\n$N一個分心，針插錯了穴位，$N痛得彎下腰來•\n"NOR,me);
    } else { 
    msg1 = HIB"\n$N一個分心，針就插錯了穴位，讓$n感到一陣昏厥•\n"NOR ;
    message_vision(msg1, me, ob2);
    }
}
      break;
     case "ghost":
     if( me->is_fighting() )
        return notify_fail("打鬥中你哪有時間替"+ob2->query("name")+"針灸！\n");     
if ( me->query("level") < 40 )
        return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");        
     if ( mysk < 60 )
        return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HBWHT+BLK"鬼陰世精訣"NOR"》•\n");
     if ( ob2->query("level") < 40 ){
        tell_object(me,ob2->query("name")+"的體質無法承受《"HBWHT+BLK"鬼陰世精訣"NOR"》•\n");
        return 1;
        }
if ( ob2->query_temp("d_a_up") >= 1 ){
         tell_object(me,ob2->query("name")+"已經接受過《"HBWHT+BLK"鬼陰世精訣"NOR"》了•\n");
     } else {             
  
message_vision(
HIR"$N將『炙穴針灸』的所有奧秘融會貫通，\n"+
   "          手中的針散發出滔滔不絕的祥光，連綿使出∼∼∼\n"+
HIW"\n    ───《"HBWHT+BLK" 鬼 陰 世 精 訣 "NOR+HIW"》───\n"+NOR
+msg,me);
         if ( (random(mysk) + random(myint) + mylv/5 ) >= random(150) ){
         ob2->add_temp("d_a_up",1);
         me->improve_spell("moxibustion",random(myint/10));
         }     
      me->start_busy(3);
      me->receive_damage("ap",mysk*2-random(myint));
      me->receive_damage("hp",mysk*2-random(myint));
      me->receive_damage("mp",mysk*2);
      call_out("enhance",4,me);
     }  
     break;
    
      case "attack":

    attackon = random(sizeof(limbs));
       limb = limbs[attackon];
       mydex = me->query("dex");
       tdex  = ob2->query("dex");
       myint = me->query("int");
       tint  = ob2->query("int");
       mylv  = me->query("level");
       tlv   = ob2->query("level");         
       mysk  = me->query_spell("moxibustion");
      tdodge = ob2->query_skill("dodge");
       mytec = me->query_Merits("tec");
       mywit = me->query_Merits("wit");
       ttec  = ob2->query_Merits("tec");
      damage = (mywit+mytec)*15+random(myint)+random(mysk);

          if(!me->is_fighting()) 
               return notify_fail("《"BLINK+HIR"神悲鬼泣訣"NOR"》是一種戰鬥技巧•\n");
          if ( ob2 == me )
               return notify_fail("用 suicide 指令會比較快:P。\n");
        if(!me->can_fight(ob2)) return 0;

     if ( me->query("level") < 35 )
        return notify_fail("你的等級不夠，無法使出《"BLINK+HIR"神悲鬼泣訣"NOR"》•\n");        
     if ( mysk < 70 )
        return notify_fail("你對炙穴針灸不夠熟練，無法使出《"BLINK+HIR"神悲鬼泣訣"NOR"》•\n");  

        if(!me->is_fighting(ob2)) me->kill_ob(ob2);
        if(!ob2->is_fighting(me)) ob2->kill_ob(me);
                
message_vision(
HIC"$N悟出蒼生萬物死傷輪迴的天地循環真理，神色悲淒\n"+
   "\n    突然一陣狂猛的寒氣自$N手中的針鋒竄出，向$n十二命門直飆而去！！！\n"+
   "\n                          "HIY"關元穴\n"+
   "                   "HIG"曲池穴        "MAG"紫宮穴\n"+
   "           "HIB"膻中穴                       "HIC"勞宮穴\n"+
   "    "HIW"至陽穴         《"BLINK+HIR" 神 悲 鬼 泣 訣"NOR+HIW" 》        "HIW+BLK"冷淵穴\n"+     
   "           "HIB"百會穴                       "HIC"曲骨穴\n"+
   "                   "HIG"章門穴        "MAG"天突穴\n"+
   "                          "HIY"極泉穴\n"+
HIC"\n        ───◎"HIR"天法恢恢渡蒼生，梟視天下無數神"HIC"◎───\n"NOR,me,ob2);

          if ( random( mysk*5 + mylv - tlv*2 - tdex - tdodge/2 + myint + mydex ) >= 30 ){
message_vision(HIB"\n十二道寒氣瞬間侵入$N十二罩門！！"+
               HIW"\n$N被這連綿的針意打的是無力招架，體內氣勁爆走而受到相當嚴重的內傷！！"NOR,ob2);
                   ob2->receive_damage("ap",damage);
                   ob2->receive_damage("hp",damage);
                   ob2->receive_damage("mp",damage);
                   ob2->start_busy(mysk/50);
        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")"NOR);
        if(ob2->query_temp("apply/show_damage") || ob2->query_temp("show_damage") )
                tell_object(ob2,HIR"("+damage+")"NOR+" ("+ob2->query("hp")+"/"+ob2->query("max_hp")+")");
        message_vision("\n", me);
        COMBAT_D->report_status(ob2);

if(limb == "頭部") ob2->receive_wound("head"     ,random(mysk/20)+mytec/5+mylv/10);
if(limb == "腳部") ob2->receive_wound("left_leg" ,random(mysk/20)+mytec/5+mylv/10);
                   ob2->receive_wound("right_leg",random(mysk/20)+mytec/5+mylv/10);
if(limb == "身體") ob2->receive_wound("body"     ,random(mysk/20)+mytec/5+mylv/10);
if(limb == "手部") ob2->receive_wound("left_arm" ,random(mysk/20)+mytec/5+mylv/10);
                   ob2->receive_wound("right_arm",random(mysk/20)+mytec/5+mylv/10);
          } else {
            message_vision(HIR"\n$N機靈的閃過寒氣，但還是受到小小的波及！"NOR,ob2,me); 
            ob2->receive_damage("hp",mysk);
        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+mysk+")"NOR);
        if(ob2->query_temp("apply/show_damage") || ob2->query_temp("show_damage") )
                tell_object(ob2,HIR"("+mysk+")"NOR+" ("+ob2->query("hp")+"/"+ob2->query("max_hp")+")");
        message_vision("\n", me);
        COMBAT_D->report_status(ob2);
           }    
                me->start_busy(4-mysk/50-myint/50); //施法動作時間
                me->receive_damage("ap",myint+ mysk*2- mytec*10); 
                me->receive_damage("mp",myint+ mysk*2- mywit*10); 
                me->improve_spell("moxibustion",random(myint/10));
      break;
        }
 return 1;
} 

void enhance()
{
    object me;
    string msg1;
    int mysk,mylv,myint,add;
    me = this_player();
    mysk = me->query_spell("moxibustion");
    myint = me->query("int");
    mylv = me->query("level");
    add = mysk/5+mylv/5;
     
if( ob2->query_temp("e_str") == 1 ){
    msg1 = HIY "$N的身影也隨著漸漸變得高大強壯，肌肉糾結百髯交錯！！！\n" NOR ;
    message_vision(msg1, ob2); 
    ob2->set_temp("addstr",add);
    ob2->apply_condition("addstr",(mysk+myint)/10+mylv);
    ob2->add_temp("apply/str",add);
    ob2->add_temp("e_str",1);
    return;
} else if ( ob2->query_temp("e_con") == 1 ){
    msg1 = HIY "$N的身影也隨著漸漸變得高大強壯，肌肉糾結百髯交錯！！！\n" NOR ;
    message_vision(msg1, ob2); 
    ob2->set_temp("addcon",add);
    ob2->apply_condition("addcon",(mysk+myint)/10+mylv);
    ob2->add_temp("apply/con",add);
    ob2->add_temp("e_con",1);
    return;
} else if ( ob2->query_temp("e_dex") == 1 ){
    msg1 = HIC"一道五彩靈光壟罩在$N頭部,$N寶像莊嚴,身邊似乎有著五色彩雲,有如神農再世•\n"NOR ;
    message_vision(msg1, ob2); 
    ob2->set_temp("adddex",add);
    ob2->apply_condition("adddex",(mysk+myint)/10+mylv);
    ob2->add_temp("apply/dex",add);
    ob2->add_temp("e_dex",1);
    return;
} else if ( ob2->query_temp("e_int") == 1 ){
    msg1 = HIC"一道五彩靈光壟罩在$N頭部,$N寶像莊嚴,身邊似乎有著五色彩雲,有如神農再世•\n"NOR ;
    message_vision(msg1, ob2); 
    ob2->set_temp("addint",add);
    ob2->apply_condition("addint",(mysk+myint)/10+mylv);
    ob2->add_temp("apply/int",add);
    ob2->add_temp("e_int",1);
    return;
} else if ( ob2->query_temp("d_a_up") == 1 ){
    msg1 = HIY "$N的身影也隨著漸漸變得高大強壯，肌肉糾結百髯交錯！！！\n" NOR ;
    message_vision(msg1, ob2); 
    ob2->set_temp("ghost",add);
    ob2->apply_condition("ghost",(mysk+myint)/10+mylv);
    ob2->add_temp("apply/damage",add);
    ob2->add_temp("apply/armor",add);
    ob2->add_temp("d_a_up",1);
    return;
} else {
    ob2->receive_damage("mp",random(mysk));
    ob2->receive_damage("ap",random(mysk));
    if ( ob2 == me ){
    message_vision(HIB"\n$N一個分心，針插錯了穴位，$N痛得彎下腰來•\n"NOR,me);
    } else { 
    msg1 = HIB"\n$N一個分心，針就插錯了穴位，讓$n感到一陣昏厥•\n"NOR ;
    message_vision(msg1, me, ob2);
    }
}
   return;
}

int do_help(string str)
{
if(!str || str != "needle") return 0; 
if( this_player()->query("level") > 25 ){
write(@HELP
        炙穴針灸使用方法:       acupuncture <功能> on <某人>
        
        非戰鬥功能：
             《療氣訣》rekee       消耗內勁點數(AP)來回覆生命點數(HP)
             《療精訣》regin       消耗魔法點數(MP)來回覆內勁點數(AP)
             《療神訣》resen       消耗內勁點數(AP)來回覆魔法點數(MP)
             《善世訣》advkee      消耗內勁點數(AP)來回覆大量生命點數(HP)
             《開天訣》sky         消耗魔法點數(MP)來回覆內勁點數(AP),生命點數(HP)
             《癒民訣》heal        消耗魔法點數(MP)來治癒受傷處 
             《陰心訣》addint      消耗大量內勁點數(AP)，魔法點數(MP)使智慧(INT)提升  
             《三焦訣》addcon      消耗大量內勁點數(AP)，魔法點數(MP)使體質(CON)提升 
             《逸飄訣》adddex      消耗大量內勁點數(AP)，魔法點數(MP)使敏捷(DEX)提升 
             《太陽訣》addstr      消耗大量內勁點數(AP)，魔法點數(MP)使力量(STR)提升 
             《神憔氣血訣》god     消耗大量魔法點數(MP)，瞬間痊癒並減低不良狀態 
             《鬼陰世精訣》ghost   消耗內勁點數(AP)，魔法點數(MP)，生命點數(HP)
                                   使物理攻擊力和物理防禦力提升 
       戰鬥功能：
             《神悲鬼泣訣》attack  消耗大量內勁點數(AP)，魔法點數(MP)對敵人的要穴發出
                                   致命的一擊
HELP);
} else {
write(@HELP
        炙穴針灸使用方法:       acupuncture <功能> on <某人>
        
        非戰鬥功能：
             《療氣訣》rekee       消耗內勁點數(AP)來回覆生命點數(HP)
             《療精訣》regin       消耗魔法點數(MP)來回覆內勁點數(AP)
             《療神訣》resen       消耗內勁點數(AP)來回覆魔法點數(MP)
             《善世訣》advkee      消耗內勁點數(AP)來回覆大量生命點數(HP)
             《開天訣》sky         消耗魔法點數(MP)來回覆內勁點數(AP),生命點數(HP)
             《癒民訣》heal        消耗魔法點數(MP)來治癒受傷處 
HELP);
} 
return 1;
}

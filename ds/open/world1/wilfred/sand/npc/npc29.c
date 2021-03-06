#include <ansi.h>
#include <path.h>
inherit NPC;

int quest();
int game(string game_index);
void eight_mirror();

int move_obj;


int *index3 = ({ 0,0,0,0,0,0,0,0 });    // 給 "卜算" 這段用的

void create()
{
  set_name("天機老人", ({ "astronomy master","master" }) );
  set("gender", "男性" );
  set("long",@LONG

    隱居中的天機老人，並無赴古劍亭武林大會的意願。天機老人
  　性淡泊名利，喜與世隔絕，現下跟他的小孫子住在一起。天機
    老人精通算術，知天機，曉地理，現下研究世傳之天機術有成
    ，準備回磐龍山破解陣法，回到古墓拜見他師父『天機子』之
    靈位，只因愛孫尚年幼，不得涉險，所以遲遲未動身。

    村內秘傳：
    另外舊磐龍遺跡完整保留下了『天機子』一生研究出的成果。
  　在大河的盡頭，山的另一邊，還留著一奇陣『伏羲石陣』，只
  　是地點隱密，到現在還沒有人親眼看見過，相傳這個石陣是天
  　機子用來保護某個東西.......。

LONG
);      
  set("age",80);
  set("level",8);
  set("race","human");

  set("chat_chance", 10);
  set("chat_msg", ({
(: command("say 一陽一陰之謂道也，有也地然後萬物生焉。") :),
(: command("say 陰根於陽，陽根於陽，獨陰不生，獨陽不長，陰陽合，循環無瑞。") :),
(: command("say 易有太極，是生兩儀，兩儀生四象，四象成八卦。") :),
(: command("say 形而上者之謂道，形而下者之謂器。") :),
"天機老人拿起筮草，在地上排出一道道卦象，似乎在推測什麼。\n",
(: command("think") :),
(: command("say 聽說無名道人的符咒很厲害，不知是什麼樣的符呢，真想看看。") :),
(: command("say 伏羲六十四卦博大精深，萬物至理，不離其宗。") :),
(: command("say 常言道：『學而有涯，知也無涯』，如欲了解伏羲六十四卦之卦意，可參考『易經』一書。") :),
(: quest :),
}));

  set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！\n");
  setup();
  set_living_name("astronomy");
  set("mirror_number",1);
  call_out("re_quest",900);
}

void init()
{
  object *obs = all_inventory( environment(this_object()) );
  int i;

  add_action("do_no_ask","ask");

  for(i=0;i<sizeof(obs);i++)
  if( obs[i]->query("victim_name") == "書僮" )
  {
    command("ack");
    message_vision(HIR"\n$N仰天長嘯：『誰！到底是誰！？竟敢殺了我的愛孫！？』\n\n"NOR,this_object());
    message_vision(WHT"\n[$N伏在他愛孫的身上，痛哭失聲]\n\n"NOR,this_object());
    command("pk");
    command("say 是你吧？！納命來 !!!!");
    for(i=0;i<sizeof(obs);i++)
      if(userp(obs[i])) this_object()->kill_ob(obs[i]);
    break;
  }
}

int do_no_ask()
{
  write("請用 say <交談的方式> 來取得所需情報。\n");
  return 1;
}

int quest()
{
  object ob = this_object();

  if(ob->query_temp("pass_quest"))
    message_vision("$N喃喃自語道：雖然磐龍山無法親自去，但總是拿回師父的牌位了。",ob);
  else command("say 真是天不從人願，這趟磐龍山之行，難道是天意命我不可成也？看來平定萬龍古墓，拜見師父的靈位，只有請別人幫忙才是。");
  return 1;
}

void relay_say(object me, string str)
{
  object ob = this_object(), obj;
  string game_index = "no";
  if( !userp(me) ) return;
  if( me == this_object() ) return;

  if(ob->query_temp("game_now"))
  {
    command("say 我還在下棋，沒看見啊？你等一下你等一下，乖乖乖乖乖，別吵。");
    return;
  }
  if(ob->query_temp("get_match_now"))
  {
    command("say 我正在為人卜算，沒看見啊？你等一下你等一下，乖乖乖乖乖，別吵。");
    return;
  }
  if(strsrch(str,"八卦鏡") !=-1)
  {
    command("say 八卦鏡就是一面八角形的鏡子，上頭八個方位刻了對應的八個卦象。");
    command("say 如果有了八卦鏡，便可以用卜算的方法，找出破解伏羲石陣的卦位。");
    command("say 聽說有八卦鏡碎片？如果你湊齊了八個方位，我可以幫你重新組合起來。");
  }
  if(strsrch(str,"卦象") !=-1 || strsrch(str,"伏羲六十四卦") !=-1)
    command("say 基本的八個卦象是『乾巽坎艮坤震離兌』，內卦外卦合而得伏羲六十四卦，若欲知詳細解釋，請參考易經一書。");
  if(strsrch(str,"河圖") !=-1 || strsrch(str,"洛書") !=-1)
    command("say 不論是河圖或是洛書，都是八卦卦象的基本來源，在易經中有詳細解釋。");
  if(strsrch(str,"磐龍山") !=-1)
    command("say 磐龍山在舊磐龍城附近，不過這之間隔了一條江，得想辦法過去才行，這是一道難關。");
  if(strsrch(str,"萬龍古墓") !=-1)
    command("say 萬龍古墓潛藏了莫大的危機 ... 我不想讓我的小孫子涉險，這是遲遲未動身的最主要原因。");
  if(strsrch(str,"伏羲石陣") !=-1)
  {
    command("say 這可是集天機術之精華於一身的奇陣！老頭兒我鑽研有成，終於能夠破解此陣！");
    command("cac");
  }
  if(strsrch(str,"靈位") !=-1)
  {
    command("say 你說的是我先師的靈位嗎？難道你有辦法幫助我嗎？磐龍山之行，我無法動身.... ");
    command("sigh");
    command("sob");
  }
  if(strsrch(str,"巫龍察") !=-1)
  {
    command("flop");
    command("say 烏龍茶？你一定是渴了吧。");
    command("boggle");
  }
  if(strsrch(str,"孫子") !=-1)
    command("say 唉... 說起我的孫子，他老是愛纏著我學天機術，但他學成之後必然前往磐龍山一探究竟，太危險了。");
  if(strsrch(str,"天機術") !=-1)
  {
    command("say 天機術，窺天知機，按八卦相生相錯之理，配以河圖，洛書之數，以得伏羲六十四卦。");
    command("say 卦意印證萬物，皆不脫離其範疇，故能上觀天文，下知地理，無所不曉。");
  }
  if((strsrch(str,"下") !=-1 && strsrch(str,"棋") !=-1) || strsrch(str,"對奕") !=-1)
  {
    command("hmm");
    command("say 你也對圍棋有興趣啊？難得，難得。");
    command("sau 來對奕吧，如何？");
    ob->set_temp("game_now",1);
    write(HIW"[你想跟天機老人下棋嗎 yes / no？] "NOR""WHT"(這可能會花掉你約一分鐘的時間)\n"NOR);
    input_to("game",game_index);
    return;
  }
  if(strsrch(str,"易經") !=-1)
    command("say 易經是自古以來最偉大的鉅著啊.. 易經所言均為天地至理，萬物相生相剋，四時節氣，都脫不了易經所闡述之範疇。");
  if(strsrch(str,"師") !=-1 || strsrch(str,"天機子") !=-1)
  {
    command("say 我的師父乃天機子是也，他己於十年前仙逝，我進來想回磐龍山探望先師的靈位，但總是無法達成心願。");
    command("say 磐龍山危機重重，我孫子年幼不得涉險。更糟的是，我的八卦鏡遺失在黃沙道，還碎成好幾片，如此看來是無法可想了。");
    command("say 八卦鏡為破解伏羲石陣之必要工具，就算破解陣法，磐龍山還是潛藏一個莫大危機，至於是什麼危機，此不足外人道也。");
  }
  if(strsrch(str,"卜算") !=-1 )
  {
    if(obj = present("eight mirror",me))
    {
      if(obj->query("get_match_yet"))
      {
        command("say 這個八卦鏡己經卜算過了，方位己定，如果你要知道它所定之方位，去問原本持有它的主人吧！");
        return;
      }
      command("say 以下演算出來的卦象，你可要牢牢的記往了。");
      write(HIC"\n[任務提示: 現在最好拿出紙筆，將以下卦象寫下來，或者您有其他"NOR);
      write(HIC"\n           記下的方法也行，因為這是破解陣法的重要關鍵。]\n\n"NOR);
      obj->set("get_match_yet",1,obj);
      this_player()->start_busy(3);
      ob->set_temp("get_match_now",1);
      call_out("get_match",1,1,obj);
    }
    else command("say 你必需要有一個完整的八卦鏡，我才能為你卜算。");
  }
  if( (strsrch(str,"組") !=-1 || strsrch(str,"復") !=-1) && strsrch(str,"合") !=-1 )
  {
    command("say 嗯 .... 我看看");
    eight_mirror();
    return;
  }
  return;
}

int accept_object(object who, object ob)
{

  int i,j = 0;
  object *user;
  if(this_object()->query_temp("get_match_now") || this_object()->query_temp("game_now"))
    return notify_fail("天機老人似乎正在忙。\n");
  if( ob->query_amount() > 0 )
  {
    message_vision("$N拿出"+chinese_number(ob->query_amount())+"枚"+ob->name(1)+"("+ob->query("id")+")給$n。\n",who,this_object());
    command("say 我那麼老了，還要"+ob->name(1)+"作啥？拿回去拿回去。");
    call_out("no_give_money",1,who,ob,ob->query_amount());
    return 1;
  }
  if(ob->query("id") == "wind seal")
  {
    command("oh");
    message_vision("$N仔細的看了看$n",this_object(),ob);
    command("say 原來無名道人的符是這樣子的啊....");
    if(j != 1)
    {
      if(random(4))
      {
        command("thank");
        destruct(ob);
        return 1;
      }
      command("say 你的禮真不輕呢，好吧，我回送你一張我所寫的符咒，你可要善加利用。");
      switch(random(4))
      {
        case 0 : new(__DIR__"obj/obj5")->move(this_object());
                 break;
        case 1 : new(__DIR__"obj/obj5")->move(this_object());
                 break;
        case 2 : new(__DIR__"obj/obj5")->move(this_object());
                 break;
        case 3 : new(__DIR__"obj/obj5")->move(this_object());
                 break;
      }
    }
    command("give " +who->query("id")+ " tally");
    this_object()->set_temp("item_give",1);
    command("say 你送我的符，我會好好收起來的。");
    destruct(ob);
    return 1;
  }
  if(ob->query("id") == "tablet")
  {
    if(this_object()->query("pass_quest"))
    {
      command("flop");
      command("say 先師的牌位己經找回來了，你這是假的吧... 滾開！");
      return notify_fail("");
    }
    destruct(ob);
    command("say 這... 這是先師的靈位... !!!!");
    command("say 師父，徒兒不肖，來給您磕頭了 !!!");
    message_vision(HIW"\n[$N伏在靈位前大哭]\n\n"NOR,this_object());
    if(who->query_temp("mission_accept"))
    {
      command("say 不愧\是我所託付的人 .....");
      command("say 這位"+RANK_D->query_respect(who)+"，感謝你的幫助，老頭兒我這有顆奇丹，是先師留下來給我的。");
      command("say 我把它送給你，望能對你有所助益。");
      new(__DIR__"obj/obj17")->move(this_object());
      command("give " +who->query("id")+ " pill");
      message_vision(HIW"\n\t[$N得到奇丹]\n\n"NOR,who);
    }
    else command("thank");
    this_object()->set_temp("pass_quest",1);
    return 1;
  }
  command("say 我這麼老了，還要"+ob->query("name")+"作什麼？拿開拿開。");
  write("["+this_object()->name(1)+"對"+ob->name(1)+"並不感興趣]\n");
  return notify_fail("");
}

int re_quest()
{
  object ob = this_object();

  if(query_temp("game_now") || query_temp("get_match_now"))
  {
    remove_call_out("re_quest");
    call_out("re_quest",10);
    return 1;
  }

  ob->delete_temp("pass_quest");
  ob->delete_temp("item_give");
  ob->delete_temp("item_give_who");

  command("say 嗯，時候不早了，不能一直待在這裡，該走了。");
  random_move();
  switch(random(4))
  {
    case 0 : ob->move("/open/world1/tmr/area/waroom");
             break;
    case 1 : ob->move(WD_PAST+"sand/room7");
             break;
    case 2 : ob->move(WD_PAST+"sand/room22");
             command("say 我回來了。");
             break;
    case 3 : ob->move(WD_PAST+"sand/room18");
             command("say 這兒這麼多人啊？秀策，生意不錯嘛。");
             break;
  }
  call_out("re_quest",300);
  return 1;
}

int game(string game_index)
{
  if(game_index == "no" || game_index == "n")
  {
    command("say 你怕了嗎？這也難怪，我可是很強的啦。");
    command("cac");
    write(HIB"[你搖了搖頭，對方真是個狂熱者，令人不敢恭維。]\n"NOR);
    this_object()->delete_temp("game_now");
    return 1;
  }
  if(game_index == "yes" || game_index == "y")
  {
    command("flip");
    command("say 好好好，我們快開始吧。");
    message_vision("$n很快的把棋盤準備好了，於是$N和$n便開始一場激烈的廝殺。\n",this_player(),this_object());
    this_player()->start_busy(10);
    call_out("game_start",1,0);
    return 1;
  }
  this_object()->delete_temp("game_now");
  command("say 你的回答我不懂耶，等你給我明確的答覆再說吧。");
  return 1;
}

int game_start(int index)
{
  object me = this_player(), ob = this_object();
  int me_sk, ob_sk;
  me_sk = me->query_skill("chess");
  ob_sk = ob->query_skill("chess");
  me->start_busy(10);
  switch(index)
  {
    case 1 : if(random(2)) message_vision(HIC"[這局由$N先下，於是$N找了個星位落下$N的第一子]\n"NOR,me);
               else message_vision(HIC"[$N獲得先下的權利，於是$N很快的在星位下了一子]\n"NOR,ob);
             break;
    case 2 : command("hmm");
             write(HIC"看來對方並非易與之輩，從開始的佈局便可看出。定石穩定，走向也相當明確。\n"NOR);
             break;
    case 3 : message_vision(HIC"啪！的一聲，雙方又落了幾子。\n"NOR,ob);
             break;
    case 4 : command("hoho");
             command("say 看我這招。");
             break;
    case 5 : message_vision(HIC"己是盤中了，目前雙方各有佔地，$N對於$n的攻勢，不甘示弱的反擊著。\n"NOR,me,ob);
             break;
    case 6 : message_vision(HIC"己是後期局勢了，現在雙方正在搶佔單官。\n"NOR,ob);
             command("say 喔喔.... 現在這樣是...");
             break;
    case 7 : message_vision(HIW"\n\t終於下完了，結果如何呢？\n\n"NOR,ob);
             break;
    case 8 : if( me_sk > 15 ) call_out("winner",1,1);
               else if( random(me_sk) > 10 ) call_out("winner",1,2);
                      else call_out("winner",1,3);
             break;
  }
  if( index < 8 ) call_out("game_start",7,++index);
  return 1;
}

void winner(int index)
{
  object ob = this_object(), me = this_player();
  if(!random(4)) index = 0;
  switch(index)
  {
    case 1 : message_vision(HIG"\n$N很輕易的便打敗了$n。\n\n"NOR,me,ob);
             command("sigh");
             message_vision("$N很得意的說道： $n，你，太弱了。隨即哈哈大笑。\n",me,ob);
             call_out("mirror",1);
             break;
    case 2 : if(random(2))
             {
               command("inn");
               message_vision(WHT"$N在幸苦的奮戰之後，終於打鸁了$n。\n"NOR,me,ob);
               command("say 一時大意輸了，"+RANK_D->query_respect(me)+"實力不錯，不過我下次可不會再輸你了");
               call_out("mirror",1);
             }
             else
             {
               message_vision(CYN"雖然$N力求反擊，但還是處於劣勢，最後輸了$n數子。\n"NOR,me,ob);
               command("spank "+me->query("id"));
               command("say 跟你對奕真是痛快，改天我們再來大戰個十局，哈哈哈！");
             }
             break;
    case 3 : message_vision(HIR"\n$N被$n殺得潰不成軍，根本無力扺擋$n的攻勢。\n\n"NOR,me,ob);
             command("nomatch "+me->query("id"));
             break;
    default : message_vision(HIW"[雙方在整地之後，發現竟是呈平手狀態，因此這局判定和局。]\n\n"NOR,ob);
              command("shrug");
              break;
  }
  ob->delete_temp("game_now");
  return;
}

int mirror()
{
  object ob = this_object(), me = this_player();
  command("say 你鸁了，老頭我該給你個什麼鼓勵才好。");
  if(ob->query("pass_quest"))
  {
    command("hmm");
    command("say 我原本想將『平定萬龍古墓，取回我先師的靈位』的任務託付於你，但是.....");
    command("say 我的八卦鏡碎片【乾】己經給另一位武林俠士了，我想，他應可以擔當重任，為我取回靈位。");
    command("say 真是抱歉，那麼，這點小意思請你收下。");
    ob->receive_money(random(10)+1);
    command("give " +me->query("id")+ " coin");
    return 1;
  }
  command("say 其實我身上還留著八卦鏡其中一塊碎片...");
  command("say 老頭兒我，實在不方便帶著我的小孫子涉險磐龍山，而且八卦鏡碎片現下不知流落何處....");
  command("say 所以，希望你能為我去一趟磐龍山，取回靈位，事成之後，自當重重酬謝。\n");
    new(__DIR__"obj/obj15")->move(ob);
  command("give " +me->query("id")+ " mirror");
  command("say 要破解萬龍古墓的第一道守護關卡『伏羲石陣』，非得用八卦鏡來卜算不可。");
  command("say 去吧，等你集全八個方位之八卦鏡碎片，再來找我，屆時我會幫你將之復合成完整的八卦鏡。");
  return 1;
}

void eight_mirror()
{
  int i, j, k;
  object *obs, me = this_player(), ob = this_object();
  object *mirror = allocate(9);
  object war_room;

war_room = load_object(WD_PAST+"sand/room92");
if(war_room->is_war())
{
  command("say 多謝你的熱心幫忙，但磐龍山之任務我己託付給他人了。");
  command("say 此人目前正在磐龍山展開一連串的行動，您請回吧。");
  return;
}
  for(i=1;i<9;i++)
  {
    obs = all_inventory(me);
    for(j=0;j<sizeof(obs);j++)
    {
      if(obs[j]->query("accept_side") == i)
      {
        k++;
        mirror[i] = obs[j];
        message_vision(WHT"$N發現身上有一塊不同方位的八卦鏡碎片，遂將它拿了出來。\n"NOR,me);
      }
      if(obs[j]->query("accept_side") == i) break;
    }
  }
  if(k != 8)
  {
    command("say 唉.... 還是沒齊全的八片碎片...");
    command("say 等齊了再來吧 ...");
    return;
  }

  for(i=1;i<9;i++)
    destruct(mirror[i]);
  command("say 太好了！！現下八片到齊，我幫你重組回來.... 看看我的手段吧。");
  message_vision(HIG"\n[$N仔細的摸索著碎片邊，找出規則，不一會兒便組合完成了]\n\n"NOR,ob);
  new(__DIR__"obj/obj16")->move(me);
  command("give "+me->query("id")+" eight mirror");
  command("say 去吧，為我平定危險的萬龍古墓，並且請回先師的靈位，我一定會重重的答謝你！");

  obs = users();
  for(i=0;i<sizeof(obs);i++)
  {
    if(obs[i]->query_temp("mission_accept") && environment(obs[i]))
    {
      obs[i]->delete_temp("mission_accept");
      message_vision(HIR"$N將委託給$n的任務取消了！\n"NOR,ob,obs[i]);
      if(environment(obs[i]) != environment(me))
        message_vision(HIR"$n將委託給$N的任務取消了！\n"NOR,obs[i],ob);
    }
  }

  message("world:world1:vision",NOR""+
  HIW"\t號外！！號外！！\n\n\t\t"+
  me->name(1)+"接受了【黃沙平原－任務：天機老人的承諾】！！\n\n"NOR,users());

  me->set_temp("mission_accept",1);
  return;
}

void no_give_money(object who, object ob, int index)
{
  command("give " +who->query("id")+ " " +index+ " " +ob->query("id"));
}

int get_match(int index1, object obj)
{
  int index4;
  object ob = this_object();
  string temp1, temp2;

  this_player()->start_busy(3);

  switch(index1)
  {
    case 1 : temp1 = "初";
             break;
    case 6 : temp1 = "末";
             break;
    default : temp1 = chinese_number(index1);
  }

  index3[index1] = random(2);
  if(index3[index1] == 1)
    temp2 = HIW"陽 ■■■■■■"NOR;
  else
    temp2 = HIW""BLK"陰 ■■　　■■";

  message_vision(NOR""WHT"$N說道： "+temp1+"爻為"+temp2+"\n\n"NOR,ob);
  if( index1 % 3 == 0 )
  {
    if(index1 == 3)
    {
      index4 = (index3[1]*1) + (index3[2]*2) + (index3[3]*4);
      obj->set("mirror_set_in",index4);
    }
    else
    {
      index4 = (index3[4]*1) + (index3[5]*2) + (index3[6]*4);
      obj->set("mirror_set_out",index4);
    }

    // 依照 2 進位法來算, 因此 [三陽爻－乾] = 1*4 + 1*2 + 1*1 = 7 , 以此類推
    switch(index4)
    {
      case 0 : temp1 = "坤";
               temp2 = "地";
               break;
      case 1 : temp1 = "震";
               temp2 = "雷";
               break;
      case 2 : temp1 = "坎";
               temp2 = "水";
               break;
      case 3 : temp1 = "兌";
               temp2 = "澤";
               break;
      case 4 : temp1 = "艮";
               temp2 = "山";
               break;
      case 5 : temp1 = "離";
               temp2 = "火";
               break;
      case 6 : temp1 = "巽";
               temp2 = "風";
               break;
      case 7 : temp1 = "乾";
               temp2 = "天";
               break;
    }
    if(index1 == 3) message_vision(HIG"\n$N說道： 由初、二、三爻得內卦為 ["+temp1+"] ，性屬"+temp2+"。\n\n"NOR,ob);
      else  message_vision(HIG"\n$N說道： 由四、五、末爻得外卦為 ["+temp1+"] ，性屬"+temp2+"。\n\n"NOR,ob);
  }

  if(index1 != 6)
    call_out("get_match",3,++index1,obj);
  else
  {
    command("sweat");
    command("say 只需算出最初方位卦象便完成了，其餘的不用算了，推演即可。");
    command("say 推演的方法請參考[易經]一書。");
    ob->delete_temp("get_match_now");
  }

  return 1;
}

#include <ansi.h>
inherit NPC;
string *rnd_say = ({
	"我是新手﹐請告訴我如何玩這個遊戲。",
	"為什麼我的精氣神都不會恢復﹖",
	"有誰可以給我一些錢﹖",
	"這裡的人都不理我﹗",
	"可不可以告訴我哪裡可以練功\﹖",
	"hi",
	"hello",
	"hmm",
	"wa...",
	"waley",
	"wait...",
	"hohoho",
	"hehe",
	"ah..",
});

varargs void drool(string msg, string who);

void create()
{
	string name, id;


set_name("奇",({"tmr"}));
	set("title", "普通百姓");
	set("gender", "男性");
	set("age", 14);
	set("attitude", "friendly");
	set("combat_exp", 100);
	set("env/wimpy", 100);
	set("chat_chance", 30);
	set("chat_msg", ({
		(: drool :),
		(: drool :),
		(: drool :),
		(: drool :),
		(: drool :),
	}) );
	setup();
	if( clonep() ) CHANNEL_D->register_relay_channel("chat");
}

int add_phrase(string who, string msg)
{
	msg = replace_string(msg, "?", "");
	msg = replace_string(msg, "？", "");
	msg = replace_string(msg, "﹖", "");
	msg = replace_string(msg, "!", "");
	msg = replace_string(msg, "！", "");
	msg = replace_string(msg, "啊", "");
	msg = replace_string(msg, "嗎", "");
	msg = replace_string(msg, "耶", "");
	msg = replace_string(msg, "吧", "");

	if( msg!="" ) {
		add("memory/" + who, ({ msg }));
		return 1;
	} else return 0;
}

string make_reply()
{
}

void relay_channel(object ob, string channel, string msg)
{
	string who, phrase;

	if( !userp(ob) || (channel != "chat") ) return;
	who = ob->query("name");

	// Don't process our own speech.
	if( ob==this_object() ) return;

	if( add_phrase(who, msg) &&	random(10) > 4 )
		drool(msg, ob->query("name"));
}

void relay_say(object ob, string msg)
{
	string who, phrase;

	if( !userp(ob) ) return;
	who = ob->query("name");

	// Don't process our own speech.
	if( ob==this_object() ) return;

	if( add_phrase(who, msg) &&	random(10) > 4 )
		drool(msg, ob->query("name"));
}

void relay_emote(object ob, string verb)
{
	if( !userp(ob) ) return;

	switch(verb) {
	case "kick":
		if( random(10)<5 ) {
			command("say 為什麼踢我﹖會痛耶﹗");
			break;
		}
	default:
		if( random(10)<5 )
			command(verb + " " + ob->query("id"));
		else
			drool();
	}
}

varargs void drool(string msg, string who)
{
	mapping mem;
	string *ob;

	mem = query("memory");
	if( !mapp(mem) ) return;

	if( !msg || !who) {
		ob = keys(mem);
		who = ob[random(sizeof(ob))];
		msg = mem[who][random(sizeof(mem[who]))];
	}

	if( (strsrch(msg, "為什麼") >= 0) ) {
		if( sscanf(msg, "%*s為什麼%s", msg)==2 ) msg = "為什麼" + msg;
		switch(random(8)) {
          case 0: command("tchat " + who + "﹐你是在問我嗎﹖"); break;
          case 1: command("tchat 關於" + msg + " ... "); break;
          case 2: command("tchat 呃 ... "); drool(); break;
          case 3: command("tchat 這個問題嘛 ...."); break;
          case 4: command("tchat " + who + "﹐知道這個問題的答案對你那麼重要嗎﹖"); break;
          case 5: command("tchat " + msg + "﹖"); break;
          case 6: command("tchat " + who + "你能不能說清楚一點﹖"); break;
          case 7: command("tchat " + who + "﹐我不懂你問的問題"); break;

		}
	}
	else if( (strsrch(msg, "你") >= 0)
	||	(strsrch(msg, "妳") >= 0)
	||	(strsrch(msg, "drooler") >= 0)
	||	(strsrch(msg, "Drooler") >= 0)) {
		if( sscanf(msg, "%*s你%s", msg) == 2 ) msg = "你" + msg;
		msg = replace_string(msg, "你", "我");
		msg = replace_string(msg, "妳", "我");
		switch(random(10)) {
          case 0: command("tchat " + who + "﹐你是說" + msg + "嗎﹖");  break;
          case 1: command("tchat 你確定" + msg + "﹖"); break;
          case 2: command("tchat " + msg + "跟你有什麼關係﹖"); break;
          case 3: command("tchat 嗯 ... " + who + "說得好"); break;
          case 4: command("tchat " + who + "你為什麼對" + msg + "這麼有興趣﹖"); break;
          case 5: command("tchat 為什麼你認為" + msg + "﹖"); break;
          case 6: command("tchat 換個話題吧"); drool(); break;
          case 7: command("tchat 才怪"); break;
          case 8: command("tchat 不一定吧﹖"); break;
          case 9: command("tchat 有這個可能 ...."); break;
          }
      }
      else if( (strsrch(msg, "我") >= 0)) {
          if( sscanf(msg, "%*s我%s", msg) == 2 ) msg = "我" + msg;
          msg = replace_string(msg, "我", "你");
          msg = replace_string(msg, "?", "");
          switch(random(8)) {
          case 0: command("tchat 你是說" + msg + "嗎﹖"); break;
          case 1: command("tchat 真的﹖" + msg + "﹖"); break;
          case 2: command("tchat 如果" + msg + "﹐我能幫你什麼忙嗎﹖"); break;
            case 3: command("tchat* hmm"); break;
            case 4: command("tchat 你認為" + msg + "﹖"); break;
  
           case 5: command("tchat 我有同感"); break;
           case 6: command("tchat 你說的「" + msg + "」我不能苟同"); break;
           case 7: command("tchat 有關「" + msg + "」的話題到此為止好嗎﹖"); break;
          }
       } else {
          switch(random(20)) {
              case 0: command("tchat 為什麼說" + msg + "?"); break;
              case 1: command("tchat 「" + msg + "」是什麼意思﹖"); break;
              case 2: command("tchat " + msg + "﹖"); break;
              case 3: command("tchat* grin"); break;
              case 4: command("thcat* smile"); break;
              case 5: command("tchat* ?"); break;
              case 6: command("tchat ...."); break;
              case 7: command("tchat* hmm"); break;
              case 8: command("tchat " + rnd_say[random(sizeof(rnd_say))]); break;
              case 9: command("tchat 你怎麼知道" + msg + "?"); break;
              case 10: command("tchat 剛剛" + who + "不是說了﹐" + msg); break;
              case 11: command("tchat 我當然知道﹐" + msg); break;
              case 12: command("tchat 然後呢﹖"); break;

              case 13: command("tchat* 真的嗎﹖"); break;
              case 14: command("tchat 我不這麼認為。"); break;
			default:
				break;
		}
	}
}

void reset()
{
	delete("memory");
}

// eq,wp 自動產生機 by -Acme-
#include <ansi.h>
#define GIFT_DIR "/open/always/game_gift/"

inherit ITEM;

string *eqs = ({ "MASK","NECK","CLOTH","ARMOR","SURCOAT","WAIST","WRISTS","HEAD",
		"SHIELD","FINGER","HANDS","LEGGING","PANTS","BOOTS" });
string *wps = ({ "AXE","BLADE","DAGGER","FORK","HAMMER","SWORD",
                "STAFF","WHIP","BOW","FIST" });
string *wpx = ({ "axe","blade","dagger","fork","hammer","sword",
                "staff","whip","bow","fist" });
string *units = ({ "面","條","件","件","件","條","個","頂","面","只","個","個","件","雙" });
string *attr = ({ "str","con","int","dex" } );
//string *attr = ({ "str","cor","int","wis","cps","dex","con","spi" });


//鎧(ARMOR)50 盾(SHIELD)30 衣(CLOTH)30 盔(HEAD)20 披(SURCOAT)20 靴(BOOTS)15 手套(GLOVES)10 
//腰(WAIST)8 指(FINGER)5 項(NECK)5 手腕(WRISTS)10 護腕(HANDS)10 綁腿(LEGGING)10 褲子(PANTS)15

int do_help(string arg);
int do_set_name(string arg);
int do_set_id(string arg);
int do_set_long(string arg);
int do_set_kind(string arg);
int do_check();
int do_change();
int do_create(string arg);

void init()
{
	add_action("do_help","help");
	add_action("do_set_name","set_name");
	add_action("do_set_id","set_id");
	add_action("do_set_long","set_long");
	add_action("do_set_kind","set_kind");
        add_action("do_check","review");
	add_action("do_change","change");
	add_action("do_create","create");
}

int do_set_name(string arg)
{
	string check;
	if( !arg ) return notify_fail("你要設定成什麼名字？\n");

        check = replace_string(arg, "$BLK$", "");
        check = replace_string(check, "$RED$", "");
        check = replace_string(check, "$GRN$", "");
        check = replace_string(check, "$YEL$", "");
        check = replace_string(check, "$BLU$", "");
        check = replace_string(check, "$MAG$", "");
        check = replace_string(check, "$CYN$", "");
        check = replace_string(check, "$WHT$", "");
        check = replace_string(check, "$HIR$", "");
        check = replace_string(check, "$HIG$", "");
        check = replace_string(check, "$HIY$", "");
        check = replace_string(check, "$HIB$", "");
        check = replace_string(check, "$HIM$", "");
        check = replace_string(check, "$HIC$", "");
        check = replace_string(check, "$HIW$", "");
        check = replace_string(check, "$NOR$", "");

	if( strlen(check) > 20 ) return notify_fail("你所設定的名字太長了(不得大於20個字元)。\n");

        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);

	write("你將物品名稱設定為["+arg+NOR"]。\n");
	set("ob_name",arg+NOR);
	return 1;
}

int do_set_id(string arg)
{
	string id1,id2;
	if( !arg ) return notify_fail("你要設定成什麼英文名字？\n");

	if( sscanf(arg,"%s,%s",id1,id2) ==2 )
	{
		if( strlen(id1) > 20 || strlen(id2) > 20 ) 
			return notify_fail("你所設定的英文名字太長了(不得大於20個字元)。\n");
		set("ob_id1",id1);
		set("ob_id2",id2);
	}
	else
	{
		if( strlen(arg) > 20 ) 
			return notify_fail("你所設定的英文名字太長了(不得大於20個字元)。\n");
		set("ob_id1",arg);
		if( query("ob_id2") ) delete("ob_id2");
	}
	write("你將物品英文名稱設定為["+arg+"]。\n");
	return 1;
}
int do_set_long(string arg)
{
	if( strlen(arg) > 200 ) return notify_fail("你設定的敘述太長了。\n");
	set("ob_long",arg);
	write("你將物品敘述設定為：\n"+arg+"\n");
	return 1;
}

int do_set_kind(string arg)
{
	int i=0,check=0;
	string type,kind;
	if( !arg ) return notify_fail("指令格式： set_kind <型式> <種類>\n");

	i=sizeof(eqs);
	while( i-- )
		if( eqs[i] == arg )
		{
			set("ob_unit",units[i]);
			check=1;
		}
		set("ob_type","armor.h");

	if( !check)
	{
		i=sizeof(wps);
		while( i-- )
		if( wps[i] == arg )
		{
			set("ob_kinds", wpx[i]);
			check=1;
		}
		set("ob_type","weapon.h");
		set("ob_unit","把");
	}

	if( !check ) return notify_fail("你設定的種類有錯誤。\n");
	set("ob_kind",arg);
	delete("make");
	write("你將物品設成["+arg+"]。\n");
	return 1;
}

int do_check()
{
	int *va,i;
	string msg,str="",sc="",*prop;

	msg = "□ 物品設定狀態 □\n\n";

	msg += " [名稱] ";
	msg += query("ob_name") ? query("ob_name") : "未設定";
	msg += query("ob_id1") ? "("+query("ob_id1") : "(none";
	msg += query("ob_id2") ? ","+query("ob_id2")+")\n" : ")\n";

	msg += " [種類] ";
	if( query("ob_type") && query("ob_kind") )
	{
		msg+=query("ob_kind")+"\n";
		switch( query("ob_type") )
		{
			case "armor.h": 
				if( query("make/armor_prop") )
				{
					prop=keys(query("make/armor_prop"));
					va=values(query("make/armor_prop"));
					i=sizeof(prop);
					while( i-- )
					{
						switch( prop[i] )
						{
						case "armor":
							str += " [防禦] ";
							str += (string)va[i]+"\n";
							break;
						case "shield":
							str += " [魔防] ";
							str += (string)va[i]+"\n";
							break;
						default:
							sc += prop[i]+":";
							sc += (string)va[i]+" ";
							break;
						}
					}
				}
				break;
			case "weapon.h": 
				msg += " [攻勢] ";
				msg += query("ob_attack")+"\n";
				if( query("make/weapon_prop") )
				{
					prop=keys(query("make/weapon_prop"));
					va=values(query("make/weapon_prop"));
					i=sizeof(prop);
					while( i-- )
					{
						switch( prop[i] )
						{
						case "hit":
							str += " [命中] ";
							str += (string)va[i]+"\n";
							break;
						default:
							sc += prop[i]+":";
							sc += (string)va[i]+" ";
							break;
						}
					}
				}
				break;
			default : msg += query("ob_type")+"\n"; break;
		}
	}
	else msg +="未設定\n";

	msg += " [重量] ";
	msg += query("ob_weight") ? query("ob_weight") +"\n" : "未設定\n";
	msg += " [價格] ";
	msg += query("ob_value") ? query("ob_value") +"\n" : "未設定\n";
	if( str ) msg += str;
	if( sc )
	{
		msg += " [附加] ";
		msg += sc;
	}
	this_player()->start_more(msg);
	return 1;
}

int do_change()
{
	int level;
	if( !query("ob_name") ) 
		return notify_fail("必需有設定名稱！\n");
	if( !query("ob_id1") )
		return notify_fail("必需有設定英文名稱！\n");

	if( !query("ob_type") || !query("ob_kind") )
		return notify_fail("必需有設定種類！\n");
        if( this_player()->query("mp") < 20 )
		return notify_fail("法力不足，無法施行。\n");
        this_player()->receive_damage("mp", 20 );
	if( !query("level") ) level=1;
	else level=query("level");
	
	delete("make");

	set("ob_weight",level*1000+random(level*1000));
 	set("ob_value",level*1000+random(level*1000));

	switch( query("ob_type") )
	{
		case "armor.h":
			switch( query("ob_kind") )
			{
				case "ARMOR": 
					set("make/armor_prop/armor", random(level*10)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level*10)+1);
					else set("make/armor_prop/shield",random(level*10)+1);
					break;
				case "SHIELD": 
					set("make/armor_prop/armor", random(level*6)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level*6)+1);
					else set("make/armor_prop/shield",random(level*6)+1);
					break;
				case "CLOTH": 
					set("make/armor_prop/armor", random(level*6)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level*6)+1);
					else set("make/armor_prop/shield",random(level*6)+1);
					break;
				case "HEAD": 
					set("make/armor_prop/armor", random(level*4)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level*4)+1);
					else set("make/armor_prop/shield",random(level*4)+1);
					break;
				case "SURCOAT": 
					set("make/armor_prop/armor", random(level*4)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level*4)+1);
					else set("make/armor_prop/shield",random(level*4)+1);
					break;
				case "BOOTS": 
					set("make/armor_prop/armor", random(level*3)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level*3)+1);
					else set("make/armor_prop/shield",random(level*3)+1);
					break;
				case "GLOVES": 
					set("make/armor_prop/armor", random(level*2)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level*2)+1);
					else set("make/armor_prop/shield",random(level*2)+1);
					break;
				case "WAIST": 
					set("make/armor_prop/armor", random(level+3)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level+3)+1);
					else set("make/armor_prop/shield",random(level*3)+1);
					break;
				case "FINGER": 
					set("make/armor_prop/armor", random(level)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level)+1);
					else set("make/armor_prop/shield",random(level)+1);
					break;
				case "NECK": 
					break;
					set("make/armor_prop/armor", random(level)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level)+1);
					else set("make/armor_prop/shield",random(level)+1);
				case "WRISTS": 
					set("make/armor_prop/armor", random(level*2)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level*2)+1);
					else set("make/armor_prop/shield",random(level*2)+1);
					break;
				case "HANDS": 
					set("make/armor_prop/armor", random(level*2)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level*2)+1);
					else set("make/armor_prop/shield",random(level*2)+1);
					break;
				case "LEGGING": 
					set("make/armor_prop/armor", random(level*2)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level*2)+1);
					else set("make/armor_prop/shield",random(level*2)+1);
					break;
				case "PANTS": 
					set("make/armor_prop/armor", random(level*3)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level*3)+1);
					else set("make/armor_prop/shield",random(level*3)+1);
					break;
			}

			if( random(level*10) > random(100) )
				add("make/armor_prop/"+attr[random(sizeof(attr))],1);
                        if( random(level*8) > random(100) && level>1 )
				add("make/armor_prop/"+attr[random(sizeof(attr))],1);
                        if( random(level*6) > random(100) && level>2)
				add("make/armor_prop/"+attr[random(sizeof(attr))],1);
                        if( random(level*4) > random(100) && level>3 )
				add("make/armor_prop/"+attr[random(sizeof(attr))],1);
                        if( random(level*2) > random(100) && level>4)
				add("make/armor_prop/"+attr[random(sizeof(attr))],1);
			break;

		case "weapon.h":
			set("ob_attack", random(level*15)+1);

			if( random(level*10) > random(100) )
				set("make/weapon_prop/hit",random(level*6)+1);
			else set("make/weapon_prop/hit",level);

			if( random(level*10) > random(100) )
				add("make/weapon_prop/"+attr[random(sizeof(attr))],1);
                        if( random(level*8) > random(100) && level>1)
				add("make/weapon_prop/"+attr[random(sizeof(attr))],1);
                        if( random(level*6) > random(100) && level>2 )
				add("make/weapon_prop/"+attr[random(sizeof(attr))],1);
                        if( random(level*4) > random(100) && level>3 )
				add("make/weapon_prop/"+attr[random(sizeof(attr))],1);
                        if( random(level*2) > random(100) && level>4)
				add("make/weapon_prop/"+attr[random(sizeof(attr))],1);
			break;
		default : 
			return notify_fail("這個種類無法使用這個指令。\n");
			break;
	}
	write("你用手在"+query("name")+"上抹了幾下，似乎起了什麼變化。\n");
	return 1;
}

int do_create(string arg)
{
	int i,*va;
	string str,*sc;
        object gift;

	if( wiz_level(this_player()) < wiz_level("(arch)") )
		return notify_fail("你沒辦法用這個指令！\n");
	
	if( !arg ) return notify_fail("必需指定檔名。\n");

        if( file_size( (GIFT_DIR+arg) ) == -2 )
		return notify_fail("這個檔名已經存在了哦！\n");

	if( !query("ob_name") ) 
		return notify_fail("必需設定名稱！\n");
	if( !query("ob_id1") )
		return notify_fail("必需設定英文名稱！\n");
        if( !query("ob_type") || !query("ob_kind") )
		return notify_fail("必需設定種類！\n");
	if( !query("ob_weight") )
		return notify_fail("必需設定重量！\n");
	if( !query("ob_unit") )
		return notify_fail("必需設定單位！\n");

	str = "//由 /std/item/game_gift.c 創造 by -Acme-\n\n";
	
	str+= "#include <"+query("ob_type")+">\n";
	str+= "#include <ansi.h>\n";
	str+= "inherit "+query("ob_kind")+";\n\n";
	str+= "void create()\n{\n";

	str+=sprintf("\tset_name( \"%s\", ({ \"%s\" }) );\n",
		query("ob_name"),
		query("ob_id1") + (query("ob_id2") ? "\",\""+query("ob_id2") : "") );

	str+="\tset_weight("+query("ob_weight")+");\n";
	str+="\tif( clonep() )\n";
        str+="\t\tset_default_object(__FILE__);\n";
	str+="\telse {\n";
	str+=sprintf("\t\tset(\"long\",\"%s\");\n", query("ob_long") ? query("ob_long") : "無" );
	str+=sprintf("\t\tset(\"unit\", \"%s\");\n",query("ob_unit"));
	str+=sprintf("\t\tset(\"value\",%d);\n\t}\n",query("ob_value"));

	if( query("make/armor_prop") )
	{
		sc=keys( query("make/armor_prop") );
		va=values( query("make/armor_prop") );
		i=sizeof(sc);
		while( i-- )
                        str+=sprintf("\tset(\"armor_prop/%s\", %d);\n",sc[i],va[i]);
	}

	if( query("make/weapon_prop") )
	{
		sc=keys( query("make/weapon_prop") );
		va=values( query("make/weapon_prop") );
		i=sizeof(sc);
		while( i-- )
			str+=sprintf("\tset(\"weaopn_prop/%s\", %d );\n",sc[i],va[i]);
		str+="\tinit_"+query("ob_kinds")+"("+query("ob_attack")+");\n";
	}

	str+="\tsetup();\n}\n";
	str+="int query_autoload() { return 1; }\n";

	if( write_file(GIFT_DIR+arg+".c",str) )
        {
                log_file( "game_gift" , getuid(this_player())+" 創造 "+query("ob_name")+"("+GIFT_DIR+arg+")於["+ctime(time())+"]。\n");
                gift=new(GIFT_DIR+arg);
                if( objectp(gift) ) gift->move(this_player());
		write("寫入檔案["+GIFT_DIR+arg+".c]成功\！\n");
                message_vision("$N口裡唸道：天靈地靈、吾之神靈…"+query("ob_name")+"。\n",this_player());
                destruct(this_object());
        }
	else return notify_fail("寫入檔案["+GIFT_DIR+arg+".c]失敗！\n");
	return 1;
}

int query_autoload() { return 1; }

int do_help(string arg)
{
	if( arg != "gift" ) return 0;
write(@HELP
  指令格式：
	一、設定：
            1. set_name <名稱>  設定物品中文名稱。(可用色碼)
            2. set_id <名稱>    設定物品英文名稱。 ex: set_id acme's blade,blade
                                則此物件會有 acme's blade 跟blade 二個英文名
	    3. set_long <敘述>	設定物品敘述。
	    4. set_kind <種類> 	設定物品種類，種類請對照下方說明。
	二、變更、檢視
            1. change           變更物品設定。(意指變更附加設定)
            2. review           檢查物品的設定。
	三、創造
	    1. create <檔名>	巫師指令，當物品設定好時，請找線上大巫師級。
				以上創造此物品。

  ◇ 武器 ◇
	AXE(斧頭)	BLADE(刀子)	DAGGER(匕首)	FORK(長槍)	HAMMER(鎚子)
	SWORD(劍)	STAFF(杖)	WHIP(鞭)	BOW(弓)		FIST(拳套)
  ◇ 防具 ◇
	ARMOR(鎧甲)	SHIELD(盾牌)	CLOTH(衣服)	HEAD(頭盔)	SURCOAT(披風) 
        BOOTS(靴子)     MASK(面具)      WAIST(腰帶)     FINGER(指環)    NECK(項鍊)
	WRISTS(護腕)	HANDS(護手)	LEGGING(綁腿)	PANTS(褲子)
  ◇ 特功 ◇ (未開放)
	一、攻擊類： 1.重擊 2.連擊 3.瀕死技
	二、牽制類： 1.忙亂
	三、恢復類： 1.活力 2.魔力 3.內力
HELP);
	return 1;
}

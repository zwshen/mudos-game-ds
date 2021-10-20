// angel.c       �Ѩ� by Zorg@DS
// #pragma save_binary
// A normal human is at least 30 kg weight
#define BASE_WEIGHT 40000
inherit F_DBASE;

mapping *combat_action = ({
        ([      "action":               "$N�|�_�k��V$n��$l���h",
                "attact_type":  "sou",  // �]�w�ޯ઺��������
                                        // ������ �ͪ�(bio) �~��(bar)
                                        // �]�k(wit)���F(sou)���(tec)
                "damage_type":  "���F����",
        ]),
        ([      "action":  "$N�ͻH�洧�b�����������L�v�L�ܡA��ۥ�$n������$n��$l�@�����h",
                "attact_type":  "bar",
                "damage_type":  "���",
        ]),
        ([      "action":               "$N���X�@��ͻH�V$n���X�@�D�g��",
                "attact_type":  "bar",
                "damage_type":  "�������",
        ]),
        ([      "action":               "$N���X�����V$n�g�X�@��ȥձj��",
                "attact_type":  "bar",
                "damage_type":  "�ζ�",
        ]),
        ([      "action":              "$N�i�}�Ҧ����ͻH��$n����V�R�ʦӱ��_�L�ƹD�j�P�x��",
                "attact_type":  "bar",
                "damage_type":  "�������",
        ]),
});

void create()
{
        seteuid(getuid());
//      set("unit","��");
//      set("gender", "�k��");
        set("can_speak", 1);
//      set("attitude", "peaceful");
        set("limbs", ({
                "�Y��", "�V��", "�ݤf", "���", "����", "�k��", "���u",
                "�k�u", "����", "�k��", "�y��", "�p��", "���L", "�k�L",
                "���}", "�k�}", "�ͻH"         }) );
}

void setup_angel(object ob)
{
        mapping my;

        my = ob->query_entire_dbase();
        if( undefinedp(my["unit"]) ) my["unit"] = "��";
        if( undefinedp(my["gender"]) ) my["gender"] = "�k��";
        if( undefinedp(my["attitude"]) ) my["attitude"] = "peaceful";
        ob->set("default_actions", (: call_other, __FILE__, "query_action" :));
        
        if( undefinedp(my["age"]) ) my["age"] = random(30) + 100;
        if( undefinedp(my["level"])) my["level"] = random(5)+1;
        if( undefinedp(my["guild_gifts"])) my["guild_gifts"] = ({4,4,8,4});

        if( undefinedp(my["str"]) ) my["str"] = (my["level"]*(15+my["guild_gifts"][0]))/15+random(my["level"]/10);
        if( undefinedp(my["con"]) ) my["con"] = (my["level"]*(15+my["guild_gifts"][1]))/15+random(my["level"]/10);
        if( undefinedp(my["int"]) ) my["int"] = (my["level"]*(15+my["guild_gifts"][2]))/10+random(my["level"]/10);
        if( undefinedp(my["dex"]) ) my["dex"] = (my["level"]*(15+my["guild_gifts"][3]))/6+random(my["level"]/10);

//      if( undefinedp(my["str"]) ) my["str"] = my["level"]*3/2+random(my["level"]/5);
//      if( undefinedp(my["con"]) ) my["con"] = my["level"]*7/4+random(my["level"]/5);
//      if( undefinedp(my["int"]) ) my["int"] = my["level"]*5/3+random(my["level"]/5);
//      if( undefinedp(my["dex"]) ) my["dex"] = my["level"]*3/2+random(my["level"]/5);
        if( !ob->query("Merits") )      // �]�w���b����
        {
                ob->set("Merits/bio",ob->query_con()/30+ob->query_dex()/30);
                ob->set("Merits/bar",ob->query_str()/30+ob->query_con()/30);
                ob->set("Merits/wit",ob->query_int()/30);
                ob->set("Merits/sou",ob->query_int()/30);
                ob->set("Merits/tec",ob->query_con()/30+ob->query_int()/30);
        }

        if( undefinedp(my["evil"]) ) my["evil"] = -random(my["level"])-1;
        if( undefinedp(my["exp"]) )
        {
                if( undefinedp(my["exp_point"]) ) my["exp_point"] = 0;
                my["exp"] = my["level"]*my["level"]*(7+my["exp_point"])+random(my["level"]*60);
                if(my["level"]>25) my["exp"]+=my["level"]*my["level"]*5;
        }
        if( userp(ob) || undefinedp(my["max_hp"]) )
        {
           if(userp(ob))
           {
                int q_con = ob->query_con();
//              my["max_hp"] = ( 30 + my["con"] * 15 );
                my["max_hp"] = ( 30 + ( q_con * q_con ) );
           } else
           {
                int q_con = ob->query_con();
                if( my["level"] <= 5 ) my["max_hp"] = 3;
                else if( my["level"] <= 15 ) my["max_hp"] = my["level"]*2;
                else if( my["level"] <= 30 ) my["max_hp"] = my["level"]*3;
                else my["max_hp"] = my["level"]*4;
                my["max_hp"] += ( q_con * q_con  );
           }
        }
        if( userp(ob) || undefinedp(my["max_mp"]) ) {
           if(userp(ob))
           {
                int q_int = ob->query_int();
//              my["max_mp"] = ( 35 + my["int"] * 15 );
                my["max_mp"] = ( 30 + q_int * my["level"] );
           } else
           {
                int q_int = ob->query_int();
                if( my["level"] <= 5 ) my["max_mp"] = 10;
                else if( my["level"] <= 15 ) my["max_mp"] = 120 + my["level"]*2;
                else if( my["level"] <= 30 ) my["max_mp"] = 320 + my["level"]*3;
                else my["max_mp"] = 500 + my["level"]*4;
                my["max_mp"] += ( q_int * my["level"] );
           }
        }
        if( userp(ob) || undefinedp(my["max_ap"]) ) {
           if(userp(ob))
           {
                int q_con = ob->query_con();
                my["max_ap"] = ( 30 + q_con * my["level"] );
           } else
           {
                int q_con = ob->query_con();
                if( my["level"] <= 5 ) my["max_ap"] = 0;
                else if( my["level"] <= 15 ) my["max_ap"] = my["level"]*2;
                else if( my["level"] <= 30 ) my["max_ap"] = my["level"]*3;
                else my["max_ap"] = my["level"]*4;
                my["max_ap"] += ( q_con * my["level"] );
           }
        }
        if( undefinedp(my["hp"]) ) my["hp"] = my["max_hp"] ;
        if( undefinedp(my["mp"]) ) my["mp"] = my["max_mp"] ;
        if( undefinedp(my["ap"]) ) my["ap"] = my["max_ap"] ;
        if(!userp(ob))
        {
//              if( undefinedp(my["combat_exp"]) ) my["combat_exp"] = random(my["level"]*2300);
                if( undefinedp(my["combat_exp"]) ) my["combat_exp"] = my["level"]*(1+my["exp_point"])*500;
                if( undefinedp(my["addition_armor"]) ) my["addition_armor"]=my["level"]*3/2+5;
                if( undefinedp(my["addition_shield"]) ) my["addition_shield"]=my["level"]/3;
                if( undefinedp(my["addition_damage"]) ) my["addition_damage"]=my["level"]*9/7;
        }         ob->set_default_object(__FILE__);
        if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + ( my["con"] )* 1200);
}

mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}






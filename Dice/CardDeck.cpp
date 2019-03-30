/*
 * _______   ________  ________  ________  __
 * |  __ \  |__  __| |  _____| |  _____| | |
 * | | | |   | |   | |    | |_____  | |
 * | | | |   | |   | |    |  _____| |__|
 * | |__| |  __| |__  | |_____  | |_____  __
 * |_______/  |________| |________| |________| |__|
 *
 * Dice! QQ Dice Robot for TRPG
 * Copyright (C) 2018-2019 w4123溯洄
 *
 * This program is free software: you can redistribute it and/or modify it under the terms
 * of the GNU Affero General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this
 * program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "CardDeck.h"
#include "RandomGenerator.h"
#include "GlobalVar.h"
#include "DiceMsgSend.h"

namespace CardDeck
{
	const std::vector<std::vector<std::string>> PublicDeck{
		{"硬币","正","反"},
		{"东方角色","博丽灵梦 / Hakurei Reimu","雾雨魔理沙 / Kirisame Marisa","神玉 / SinGyoku","魅魔 / Mima","菊理 / Kikuri","矜羯罗 / Konngara","幽幻魔眼 / YuugenMagan","依莉斯 / Elis","萨丽爱尔 / Sariel","玄爷 / Genjii","里香 / Rika","明罗 / Meira","魔梨沙 / Marisa","Flower～战车 / Furawa～sensha","邪眼西格玛 / ibiruai sigma","爱莲 / Ellen","小兔姬 / Kotohime","卡娜·安娜贝拉尔 / Kana Anaberal","朝仓理香子 / Asakura Rikako","北白河千百合 / Kitashirakawa Chiyuri","冈崎梦美 / Okazaki Yumemi","咪咪号（咪咪酱） / Mimichan","留琴 / Ru~koto","玛○奇 / Ma maru chi","苏格拉底 / Sokuratesu","奥莲姬 / Orange","胡桃 / Kurumi","艾丽/ Elliy","幽香 / Yuka","梦月 / Mugetu","幻月 / Gengetu","萨拉 / Sara","露易兹/ Luize","爱丽丝 / Alice","雪 / Yuki","舞 / Mai","梦子 / Yumeko","神绮 / Shinki","露米娅 / Rumia","大妖精 / Daiyousei","琪露诺 / Cirno","红美铃 / Hoan Meirin","小恶魔 / Koakuma","帕秋莉·诺蕾姬 / Patchouli Knowledge","十六夜咲夜 / Izayoi Sakuya","蕾米莉亚·斯卡蕾特/ Remilia Scarlet","芙兰朵露·斯卡蕾特/ Flandre Scarlet","冴月麟 / Satsuki Rin","毛玉 / gedama","蕾蒂·霍瓦特洛克/ Letty Whiterock","橙 / Chen","爱丽丝·玛格特洛依德 / Alice Margatroid","莉莉霍瓦特 / Lily White","露娜萨·普莉兹姆利巴 / Lunasa Prismriver","梅露兰·普莉兹姆利巴 / Merlin Prismriver","莉莉卡·普莉兹姆利巴 / Lyrica Prismriver","魂魄妖梦 / Konpaku Youmu","西行寺幽幽子 / Saigyouji Yuyuko","八云蓝 / Yakumo Ran","八云紫 / Yakumo Yukari","魂魄妖忌 / Konpaku Youki","蕾拉·普莉兹姆利巴 / Leira Prismriver","伊吹萃香 / Ibuki Suika","莉格露·奈特巴格 / Wriggle Nightbug","米斯蒂娅·萝蕾拉 / Mystia Lorelei","上白泽慧音 / Kamishirasawa Keine","因幡帝 / Inaba Tewi","铃仙·优昙华院·因幡 / Reisen Udongein Inaba","八意永琳 / Yagokoro Eirin","蓬莱山辉夜 / Houraisan Kaguya","藤原妹红 / Huziwara no Mokou","射命丸文 / Syameimaru Aya","梅蒂欣·梅兰可莉 / Medicine Melancholy","风见幽香 / Kazami Yuka","小野塚小町 / Onozuka Komachi","四季映姬·亚玛萨那度 / Shikieiki Yamaxanadu","秋静叶 / Aki Shizuha","秋穰子 / Aki Minoriko","键山雏 / Kagiyama Hina","河城荷取 / Kawasiro Nitori","犬走椛 / Inubashiri Momizi","东风谷早苗 / Kochiya Sanae","八坂神奈子 / Yasaka Kanako","洩矢诹访子 / Moriya Suwako","永江衣玖 / Nagae Iku","比那名居天子 / Hinanawi Tenshi","琪斯美 / Kisume","黑谷山女 / Kurodani Yamame","水桥帕露西 / Mizuhashi Parsee","星熊勇仪 / Hoshiguma Yugi","古明地觉 / Komeiji Satori","火焰猫燐 / Kaenbyou Rin","灵乌路空 / Reiuzi Utsuho","古明地恋 / Komeiji Koishi","僵尸妖精 （怨灵附身妖精） / Zombie Fairy","娜兹玲 / Nazrin","多多良小伞 / Tatara Kogasa","云居一轮 & 云山 / Kumoi Ichirin & Unzan","村纱水蜜 / Captain Murasa Minamitsu","寅丸星 / Toramaru Syou","圣白莲 / Hiziri Byakuren","封兽鵺 / Houjuu Nue","命莲 / Myouren","大鲶鱼 / Oo-Namazu","太岁星君 / Taisai Sei-kun","大太法师 / Daidarabotchi","非想天则 / Hisoutensoku","提泰妮娅 / Titania","歌利亚人偶 / Goliath Doll","姬海棠果 （姬海棠羽立 / 姬海棠极） / Himekaidou Hatate","幽谷响子/ Kasodani Kyouko","宫古芳香/ Miyako Yoshika","霍青娥 / Seiga NyanNyan）","苏我屠自古 / Soga no Toziko","物部布都 /　Mononobe no Futo","丰聪耳神子 / Toyosatomimi no Miko","二岩猯藏 / Hutatsuiwa Mamizou","秦心 / Hata no Kokoro","秦河胜 / Hata no Kawakatsu","若鹭姬 / Wakasagihime","赤蛮奇 / Sekibanki","今泉影狼 / Imaizumi Kagerou","九十九弁弁 / Tsukumo Benben","九十九八桥 / Tsukumo Yatsuhashi","鬼人正邪 / Kijin Seija","少名针妙丸 / Sukuna Shinmyoumaru","堀川雷鼓 / Horikawa Raiko","宇佐见堇子 / Usami Sumireko","清兰 / Seiran","铃瑚 / Ringo","哆来咪·苏伊特 / Doremy Sweet","稀神探女 / Kisin Sagume","克劳恩皮丝 / Clownpiece","纯狐 / Junko","赫卡提亚·拉碧斯拉祖利 / Hecatia Lapislazuli","依神女苑 / Yorigami Jyoon","依神紫苑 / Yorigami Shion","爱塔妮缇拉尔瓦 / Eternity Larva","坂田合欢乃 / Sakata Nemuno","高丽野阿吽 / Komano Aunn","矢田寺成美 / Yatadera Narumi","尔子田里乃 / Nishida Satono","丁礼田舞 / Teireida Mai","摩多罗隐岐奈 / Matara Okina","森近霖之助 / Morichika Rinnosuke","朱鹭子 / Tokiko","水獭少女/ Kawauso no Shoujyo","桑尼米尔克 / Sunny Milk","露娜切露德 / Lunar Child","斯塔萨菲雅 / Star Sapphire","绵月丰姬 / Watatsuki no Toyohime","绵月依姬 / Watatsuki no Yorihime","铃仙二号 / Reisen","稗田阿求 / Hieda no Akyuu","茨木华扇 / Ibarakasen","本居小铃 / Motoori Kosuzu","易者 / The Fortune-teller","宇佐见莲子 / Usami Renko","玛艾露贝莉·赫恩 / Maribel Hearn（梅莉 / Merry）"},
		{"调查员职业","会计师","杂技演员","演员-戏剧演员","演员-电影演员","事务所侦探、保安","精神病医生（古典）","动物训练师","文物学家（原作向）","古董商","考古学家（原作向）","建筑师","艺术家","精神病院看护","运动员","作家（原作向）","酒保","猎人","书商","赏金猎人","拳击手、摔跤手","管家、男仆、女仆","神职人员","程序员、电子工程师（现代）","黑客/骇客（现代）","牛仔","工匠","罪犯-刺客","罪犯-银行劫匪","罪犯-打手、暴徒","罪犯-窃贼","罪犯-欺诈师","罪犯-独行罪犯","罪犯-女飞贼（古典）","罪犯-赃物贩子","罪犯-赝造者","罪犯-走私者","罪犯-混混","教团首领","除魅师（现代）","设计师","业余艺术爱好者（原作向）","潜水员","医生（原作向）","流浪者","司机-私人司机","司机-司机","司机-出租车司机","编辑","政府官员","工程师","艺人","探险家（古典）","农民","联邦探员","消防员","驻外记者","法医","赌徒","黑帮-黑帮老大","黑帮-马仔","绅士、淑女","游民","勤杂护工","记者(原作向)-调查记者","记者(原作向)-通讯记者","法官","实验室助理","工人-非熟练工人","工人-伐木工","工人-矿工","律师","图书馆管理员（原作向）","技师","军官","传教士","登山家","博物馆管理员","音乐家","护士","神秘学家","旅行家","超心理学家","药剂师","摄影师-摄影师","摄影师-摄影记者","飞行员-飞行员","飞行员-特技飞行员（古典）","警方(原作向)-警探","警方(原作向)-巡警","私家侦探","教授（原作向）","淘金客","性工作者","精神病学家","心理学家、精神分析学家","研究员","海员-军舰海员","海员-民船海员","推销员","科学家","秘书","店老板","士兵、海军陆战队士兵","间谍","学生、实习生","替身演员","部落成员","殡葬师","工会活动家","服务生","白领工人-职员、主管","白领工人-中高层管理人员","狂热者","饲养员"},
		{"煤气灯","任意选择一个有(D)记号的特征。","高龄(D):年龄追加[(1D3+1)*10]岁,参照6版标准规则,超过30岁后开始获得EDU加值,40岁以后开始对于身体属性造成减值。","优雅的岁数: 40岁开始对身体能力造成减值的规则改为从50岁开始。","白化病患者(D):STR,CON,SIZ,DEX,POW,APP中的任意一项减少3点。在明亮阳光下时[侦察]技能值减少[1D4-1]点,长时间受到光照的话会受到1点以上的HP伤害。白化病人在人群中很显眼并可能被他人用有色目光看待。","酒精中毒(D):CON-1。STR,DEX,POW,APP中任意一项减少1点。为了避免陷入酩酊大醉需要通过一个SAN CHECK。陷入疯狂的情况下,调查员可能会寻求酒精来逃避现实。","警戒:不易被惊吓到。潜伏时一直都保持着能够随时[侦察]或者[聆听]的状态。","同盟者:投掷一个D100来决定同盟的力量/数量和出现的频率(D100的出点越大可能能够获得越有利的同盟)。用途不限。","双手灵活:调查员可以灵活的使用他的任意一只手而不会受到非惯用手的惩罚。","讨厌动物(D):技能和动物有关时技能成功率减少[1D6*5]点。","艺术天才:音乐,写作之类的艺术技能增加[INT*5]%。","运动:运动系技能获得加值=选择一个技能+30%,或者选择两个技能各+20%,或者选择三个技能各+10%。","夜视强化:日落西山后视觉相关惩罚只有常人的一半。","累赘(D):调查员出生于世家但是却没能达到家人的期待,或者不服管教。对于交涉系技能可能会造成影响而减少[1D3*10]%。","领导者资质:POW+1D2,交涉系技能+[INT*5]%。","打斗者:[拳击]或者[擒拿]+[1D4*5]%,每回合可以进行两次[拳击]或者[擒拿],攻击成功时+1点伤害。","笨拙(D):大失败的几率变成通常的2倍,并且大失败时可能会招致灾难。","收藏家:调查员有收集硬币,书,昆虫,艺术作品,宝石,古董之类的爱好。","身体障碍(D):失去了身体的一部分。投掷一个D6。1~2=脚,3~4=手,5=头部(投掷D6,1~3=眼睛,4~6=耳朵),6=玩家自己选择。失去脚的话DEX-3，STR或者CON-1,MOVE只有常人的一半,所有运动系技能-25%。失去手腕的话STR-1,DEX-2,所有的操作系技能-15%,使用武器会受到限制。失去眼睛的话[侦察]和火器技能等全部-35%,另外投掷一个[幸运],失败的话APP-1D2。失去耳朵的话APP-1D3,[聆听]等和耳朵有关的技能全部-30%。","再投掷三次,由玩家选择其中一个作为特征。","再投掷三次,玩家和KP各选择一个特征。","再投掷一次,获得那个特征:特征具有(D)时,玩家可以再额外选择一个其他任意特征获得。特征没有(D)时,玩家必须再同时选择一个(D)特征。","诅咒(D):调查员被吉普赛人,魔女,法师,外国原住民等施予了诅咒,诅咒效果等同[邪眼]咒文或者由KP决定。KP也可以决定解除诅咒的条件。","黑暗先祖(D):调查员具有邪恶的一族,外国人,食人族,甚至神话生物的血统。投掷一个D100,出点越大,血统也越可怖。","听觉障碍(D):[聆听]减少[1D4*5]%。","绝症缠身(D):调查员身患绝症[癌症,失明,梅毒,结核等],绝症对调查员造成恶劣影响,至少也失去了1点CON,如果病情继续恶化的话还会继续失去其他能力值。投掷一个D100来决定剩余寿命,出点越大寿命越长。","钟楼怪人(D):调查员具有巨大的伤痕或者身体变形等特征,对APP造成至少减少1D4点影响。对交涉系技能也可能也造成影响[(失去的APP)*5%]。","酒豪:不易喝醉。酒精作为毒素处理的情况下, POT值只有他人的一半。","鹰眼:[侦察]增加[2D3*5]%。","敌人(D):有对调查员不利的敌人存在,投掷一个D100来决定敌人的力量/数量,数值越大越恶劣。用途不限。","擅长武器:火器类射程+50%。近战类武器成功率+5%或者伤害增加1D2。并且武器不易被破坏(具有更多的耐久度),或者入手的武器具有比一般的武器更高的品质。","传家宝:调查员拥有绘画,书籍,武器,家具等具有高价值的宝物。也可能是模组中追加的宝物的持有人。","俊足:DEX+1。再投掷一个D6,1~4时MOVE+1,5~6时MOVE+2。","赌徒(D?):进行一次[幸运]鉴定。成功的话调查员获得[(INT+POW)*2]%的[赌博]技能。失败的话只有[INT或者POW*1]%的技能值,资产减少[1D6*10]%,并且调查员遇到赌博时需要通过一个SAN CHECK才能克制自己。","擅长料理:获得 [(INT或者EDU)*5]%的[手艺(料理)]技能。","听力良好:[聆听]+[2D3*5]%。","洞察人心:[心理学]+ [2D3*5]%。","反应灵敏:投掷1D6。1~3=DEX+1,4~5=DEX+2,6=DEX+3。","驱使动物:技能和动物有关时获得[(1D6+1)*5]的加值,例如骑马,驾驶马车,特定情况的藏匿,潜行等。","没有特征但是可以选择任意技能(可多选)获得总计3D20点技能加值。","玩家自己选择一个特征。","再投掷三次,玩家和KP各选择一个。","贪婪(D):对调查员来说金钱至上。任何状况下都优先考虑金钱。为此欺骗他人也是正常的,欺骗对象也包含其他调查员。","悲叹人生:SAN-1D10,玩家和KP给调查员设定一个背景(失去爱人,子孙或者其他血亲的悲剧)。","憎恶(D):玩家和KP商议决定,调查员对于特定的国籍,人种或者宗教具有无理由的反感。调查员接触此类人群时会表现出敌意。","比马还要健壮:CON+1D3。","快乐主义者:追求个人的喜悦(美食,饮品,性,衣装,音乐,家具等)。为此浪费了[(1D4+2)*10]%的资产。通过一个[幸运]鉴定,失败的话因为这种放纵的生活而失去1点STR,CON,INT,POW,DEX或者APP。","骑手:[骑马]技能+[(1D6+1)*10]%。","易冲动(D):有不考虑后果轻率的行动的倾向。根据情况可能需要通过一个减半的[灵感]鉴定来使头脑冷静。","巧妙:二选一。A)[灵感]+10%,获得可以临时组装或者发明一些装置的能力。B)武器以外的操纵系技能获得加值,只选择一个技能的话+30%,选择2个技能各+20%,3个各+10%。","疯狂(D):SAN-1D8。玩家和KP商议给予调查员一个精神障碍。","土地勘测员:调查员对某一篇地域了解的非常详细(例:建筑配置,道路,商业,住民,历史等)。对应的区域应为都市某一块区域或者单个农村之类的较狭小的范围。对于这篇区域的详细情况调查员通过[知识]或者[灵感]鉴定即可知晓。","意志顽强:POW+1D3,san也获得对应的上升。","花花公子:APP+1D3,和异性交往有关的交涉技能+[1D3*10]%。","持有高额财产:调查员拥有某种具有巨大价值的东西(例:船只,工厂,房屋,矿山,大块的土地等)。这些东西可能需要调查员花费很大的时间和精力在这里，玩家和KP要慎重的决定。","语言学家:调查员即使语言不通也有可能和对象成功的交流,增加一个辅助技能[语言学家],初期技能值为[INT或者EDU*1]%。","家人失踪:调查员有着失踪很久的家人,有可能会在模组中登场(例:兄弟/姐妹/或者其他亲人遭遇海难,死在海外,被其他亲戚带走等情况)。","忠诚:调查员不会抛弃自己的家人,朋友,伙伴,在力所能及的范围内一定会帮助他们。这种性格也使他和自己周围的人群交涉时获得10%的加值。","魔术素质:学习咒文时只需要正常的一半时间,成功率也增加[INT*1]%。","虽然没有特侦但是职业技能值获得额外的3D20的技能点。","玩家自己选择一个特征。","虽然没有特征,但是调查员的持有现金为通常规则的2倍。","魔术道具:KP可以给予调查员一个魔术道具(可以杀伤神话生物的附魔武器,召唤神话生物的专用道具,占卜用品,POW储藏器等等)。调查员如果想要知道这件道具的详细性质需要通过一个[POW*1]的鉴定。","射击名人(手枪,步枪以及霰弹枪中选择一项):选择的这项火器技能+[2D3*5]%。","认错人:调查员被频繁的被误认为其他人,通常都会是些有着恶评的人物(罪犯,身怀丑闻的恶人之类的)。模组中在合适的情况下[幸运]可能会被降为原本的一半(简单来说,调查员因为某些理由获得其他人的犯罪历史,恶名,通过诈骗获得的财富或者权力这样的身份或者特征)。","天气预报:通过一个[灵感]鉴定调查员就可以得知[1D6+1]小时里的正确天气情况。有多大的降雨量,下雨的场所,风级,持续时间等等。","对外观的强迫观念(D):APP+1,但是调查员为了让自己看起来亮丽动人而花费大量的金钱来购买华贵的服饰和饰物。储蓄和资产减半。","古书:调查员拥有和模组有关的重要书籍资料或者它的复印(例:杂志,黑魔术书籍,历史书,圣经,神话魔导书,地图等等)。KP可以决定这件道具的性质和价值。","试炼生还者(D):SAN-1D6。调查员拥有从恐怖环境中生还的经验(海难,战争,恐怖分子劫持,地震等等)。因为这个经历可能给调查员带来某种长久的影响(通常程度的恐怖症状,或者其他的精神障碍等)。","孤儿:调查员相依为命的家人都不在了,或者不知道自己真正的家人是谁。","其他语言:调查员可以追加获得一项其他语言技能。技能值为[1D4*INT]%。","野外活动爱好者:[导航],[自然史],[追踪]各增加[(2D3+1)*5]%(分别投掷)。","寄托爱意:模组中登场的某位角色对调查员怀有憧憬。由KP决定是哪位角色,为什么以及怀有何种程度。","身怀爱意(D):调查员对其他角色怀有憧憬。由KP决定喜欢谁,为什么以及何种程度。","麻痹(D):调查员因精神,疾病等原因苦于身体抽搐,扭曲等症状。各鉴定一次[幸运],失败的话减少1D2点DEX和1点APP。","超常现象经历:调查员曾经经历过难以说明的遭遇(幽灵,黑魔术,神话生物,超能力等)。玩家和KP讨论决定其内容并失去最多1D6点SAN值。","大肚子(D):这位调查员怎么说也太胖了点。鉴定一次[幸运],失败的话投掷一个D6,1~3 CON-1,4~6 APP-1。","说服力:[劝说]+[(2D3+1)*5]%。","宠物:调查员有养狗,猫或者鸟类。","虽然没有特征但是任意技能获得3D20点技能点。","再投掷一次,获得那个特征:特征具有(D)时,玩家可以再额外选择一个其他任意特征获得。特征没有(D)时,玩家必须再同时选择一个(D)特征。","虽然没有特征但是职业技能值额外获得3D20点技能点。","恐怖症/疯狂(D):调查员身患恐怖症状或者疯狂症状。参考6版标准规则随机决定症状,或者选择想要的症状。遭遇到自身症状根源的恐怖或者物品时,如果SAN CHECK失败,那么调查员将无法抑制自己的恐怖或者被魅惑。","权力/阶级/企业地位:调查员在政治,经济或者甚至军事环境里持有某种程度的权力。投掷D100,出点越大权力越大。企业地位影响融资,政治地位可能所属某种政府机关,军队地位远超本身拥有的军衔也说不定。[信用+25%。详细的情况和KP商议决定。","以前的经验:玩家可以选择获得[(INT或者EDU)*5]%的职业技能点数。","预知梦:由KP决定,游戏中玩家会做一个预言未来的梦。这大概会需要一个[POW*3]的鉴定。梦境没有必须符合现实的必要,如果梦境中见到的景象十分恐怖的话那么会失去一些SAN值(现实中见到相同景象失去SAN值的10%左右)。鉴定失败的话玩家会获得错误的预言。","繁荣:调查员的年收入和资产变成2倍。[信用]增加[1D4*5]%。调查员的事业很成功,或者调查员给富翁,持有权力的人做事或者与他们共事。","心理测量:接触某些物体时(或者抵达某个地方时),通过一个POW*1的鉴定,成功的话可以窥视到这个物品/地方的过去。这个能力的正确度由KP决定。这个能力消耗1D6点MP。因为幻觉也可能失去SAN值(和上述的”预知梦”类似,损失通常的10%左右)。","健谈者:[快读交谈]+[2D4*5]%。调查员有着非常厉害的语言术,可以通过讲故事获得朋友的信任,降低敌人的敌意,赚到一顿免费的餐点也是可能的。","罕见的技能:调查员通过一个[INT*4]%的鉴定的话,可能会持有一些生活中完全不常见,或者一般来说不会有的技能。罕见的语言,格斗技,驾驶热气球之类,和KP商议决定。","红发:调查员有着一头好像燃烧着一般的红发,非常显眼(没有其他效果)。","评价(D?):鉴定一次[幸运]。成功的话调查员被人尊敬(设定其理由),调查员在自家所在的村子/都市中所有的交涉系技能获得15%的加值。[幸运]失败的话调查员获得极坏的评价,所有的交涉系技能-15%。KP也可以决定通过良好的业绩来抵消这个恶评。","报复追求者:调查员相信自己受到了不公正的待遇并且对导致自己受到这种恶意的对象进行报复行为。玩家和KP讨论决定敌人的真身。投掷一个D100来决定敌人的强度和调查员受到这种不公正的程度。","伤痕:鉴定一次[幸运]。成功的话伤痕没有影响调查员的外观,甚至彰显其英勇也说不定。失败的话失去1D3点APP,交涉系技能也减少[1D3*5]%。","科学的精神:[灵感]+5%。并且选择一个思考类技能+30%并再选择2个思考系技能+20%或者所有其他思考系技能+10%。","秘密(D?):调查员有着决不能告诉别人的秘密。调查员的邻居可能会有些线索也说不定。调查员可能是个罪犯,间谍,或者卖国贼之类的也说不定。内容由玩家和KP商议决定。","秘密结社:调查员所属于秘密主义的团体,可能会是共济会,蔷薇十字团,神志主义者,炼金术师结社,光明会之类团体的一员。或者是地下医学研究者之类的犯罪/阴谋组织的一员。","自学:EDU+1D3,并增加因此获得的技能值。","可疑的过去/绯闻(D):调查员过去曾经做过一些惹人怀疑的事情(卖淫,偷人等),或者曾经犯下过某些重大罪行。所有的交涉系技能减少[1D3*10]%。","再投掷一次,获得那个特征:特征具有(D)时,玩家可以再额外选择一个其他任意特征获得。特征没有(D)时,玩家必须再同时选择一个(D)特征。","再投掷两次并获得那两个特征。","投掷三次,玩家和KP各选择一个特征。","病弱(D):CON-1D3。","巧妙的手法:[钳工]技能增加[DEX*5]%,可以在偷窃或者魔术的时候使用。","迟缓(D):MOVE-1。","失去名誉(D):探索者因为国籍,性别,人种,宗教或者过去的犯罪记录等原因失去了社会上的名誉地位。作为其影响,调查员可能减少自由活动时间甚至所有的交涉系技能减少[1D4*10]%甚至更多。具体的影响玩家和KP商议决定。","元军人:调查员获得[INT*5]点的技能点加到士兵的职业技能上。","咒文知识:由KP决定!调查员最多可以获知1D3种咒文。SAN值减少1D6点。","胆小(D):调查员见到血液或者流血就会感觉到身体不适,失去更多的SAN值。也可能因为疾病的原因无法靠近或通过流血现场。","坚毅:调查员不受到现实中的血迹或者流血的影响。遭遇血迹和流血时SAN损失为最小值,即使见到最残虐的场合(大量被撕裂的人,被猎奇杀死的尸体等)也最多只减少通常的一半。","比公牛还要强韧:STR+1D3。","迷信(D):调查员迷信不疑,依赖着护身符,仪式或者愚蠢的信念。遭遇超自然现象的时候比通常多损失1点SAN值,即使原本不损失的情况下可能变成损失1点。","同情心:调查员选择一个交涉系技能+30%或者选择两个各+20%,然后额外再选择一个+10%。","意外的帮手:调查员因为一些缘由拥有一个对自己忠实并帮助自己的协助者。KP来决定这个协助者的真身和影响(依旧可以D100来决定)。并且D100也决定其频率。","看不见的财产:调查员有一笔自己不知道的财产。这可能是亲人遗赠的或者理事会之类授予的。这可能会是一块土地,房屋或者事业。这依旧可以用D100来决定去价值程度。","虚弱(D):STR-1D3。","戴眼镜(D):调查员要看清东西必须戴眼镜。鉴定一个[幸运],成功的话眼镜只在读书或者进行精细工作的时候才需要。失败的话会在激烈运动等情况时会感觉到不能自由行动。不戴眼镜的话和视觉关联的技能减少[1D3*10]%(这个惩罚即使幸运成功也一样)。","彬彬有礼:调查员的[信用]+10%,真是个有礼貌的绅士(淑女)。","孩子(D):调查员的年龄变成[10+2D3]岁。最大EDU变成[年龄的1/2+2],DEX+1,STR,CON,APP中任意一项+1。玩家和KP商议决定,调查员大概依旧和家人住在一起,职业等也需要重新修正。","任意选择一项特征。","投掷两次,玩家任意选择其中一项特征。"},
		{"个人描述","结实的","英俊的","笨拙的","机灵的","迷人的","娃娃脸","聪明的","邋遢的","死人脸","肮脏的","耀眼的","书呆子","年轻的","疲倦脸","肥胖的","啤酒肚","长头发","苗条的","优雅的","稀烂的","矮壮的","苍白的","阴沉的","平庸的","乐观的","棕褐色","皱纹人","古板的","狐臭的","狡猾的","健壮的","娇俏的","筋肉人","魁梧的","迟钝的","虚弱的"},
		{"思想信念","１：你信仰并祈并一位大能。（例如毗沙门天、耶稣基督、海尔·塞拉西一世）","２：人类无需上帝。（例如坚定的无神论者，人文主义者，世俗主义者）","３：科学万能！科学万岁！你将选择其中之一。（例如进化论，低温学，太空探索）","４：命中注定。（例如因果报应，种姓系统，超自然存在）","５：社团或秘密结社的一员。（例如共济会，女协，匿名者）","６：社会坏掉了，而你将成为正义的伙伴。应斩除之物是？（例如毒品，暴力，种族歧视）","７：神秘依然在。（例如占星术，招魂术，塔罗）","８：诸君，我喜欢政治。（例如保守党，共产党，自由党）","９：“金钱就是力量，我的朋友，我将竭尽全力获取我能看到的一切。”（例如贪婪心，进取心，冷酷心）","１０：竞选者/激进主义者。（例如女权运动人，平等主义家，工会权柄）"},
		{"重要之人","１：父辈。（例如母亲，父亲，继母）","２：祖父辈。（例如外祖母，祖父）","３：兄弟。（例如妹妹，半血亲妹妹，无血缘妹妹）","４：孩子。（儿子或女儿）","５：另一半。（例如配偶，未婚夫，爱人）","６那位指引你人生技能的人。指明该技能和该人。（例如学校教师，师傅，父亲）","７：青梅竹马。（例如同学，邻居，幼驯染）","８：名人。偶像或者英雄。当然也许你从未见过他。（例如电影明星，政治家，音乐家。）","９：游戏中的另一位调查员伙伴。随机或自选。","１０：游戏中另一外ＮＰＣ。详情咨询你的守秘人"},
		{"重要之人理由","１：你欠了他们人情。他们帮助了你什么？（例如，经济上，困难时期的庇护，给你第一份工作）","２：他们教会了你一些东西。（例如，技能，如何去爱，如何成为男子汉）","３：他们给了你生命的意义。（例如，你渴望成为他们那样的人，你苦苦追寻着他们，你想让他们高兴）","４：你曾害了他们，而现在寻求救赎。例如，偷窃了他们的钱财，向警方报告了他们的行踪，在他们绝望","时拒绝救助）","５：同甘共苦。（例如，你们共同经历过困难时期，你们携手成长，共同度过战争）","６：你想向他们证明自己。（例如，自己找到工作，自己搞到老婆，自己考到学历）","７：你崇拜他们。（例如，崇拜他们的名头，他们的魅力，他们的工作）","８：后悔的感觉。（例如，你本应死在他们面前，你背弃了你的誓言，你在可以助人之时驻足不前）","９：你试图证明你比他们更出色。他们的缺点是？（例如，懒惰，酗酒，冷漠）","１０：他们扰乱了你的人生，而你寻求复仇。发生了什么？（例如，射杀爱人之日，国破家亡之时，明镜两分之际）"},
		{"意义非凡之地","１：你最爱的学府。（例如，中学，大学）","２：你的故乡。（例如，乡下老家，小镇村，大都市）","３：相识初恋之处。（例如，音乐会，度假村，核弹避难所）","４：静思之地。（例如，图书馆，你的乡土别墅，钓鱼中）","５：社交之地。（例如，绅士俱乐部，地方酒吧，叔叔的家）","６：联系你思想/信念的场所。（例如，小教堂，麦加，巨石阵）","７：重要之人的坟墓。（例如，另一半，孩子，爱人）","８：家族所在。（例如，乡下小屋，租屋，幼年的孤儿院）","９：生命中最高兴时的所在。（例如，初吻时坐着的公园长椅，你的大学）","１０：工作地点。（例如，办公室，图书馆，银行）"},
		{"宝贵之物","１：与你得意技相关之物。（例如华服，假ＩＤ卡，青铜指虎）","２：职业必需品。（例如医疗包，汽车，撬锁器）","３：童年的遗留物。（例如漫画书，随身小刀，幸运币）","４：逝者遗物。（例如烛堡，钱包里的遗照，信）","５：重要之人给予之物。（例如戒指，日志，地图）","６：收藏品。（例如撤票，标本，记录）","７：你发掘而不知真相的东西。答案追寻中。（例如，橱柜里找到的未知语言信件，一根奇怪的从父亲处继承来的来源不明的风琴，花园里挖出来的奇妙的银球）","８：体育用品。（例如，球棒，签名棒球，鱼竿）","９：武器。（例如，半自动左轮，老旧的猎用来福，靴刃）","１０：宠物。（例如狗，猫，乌龟）"},
		{"调查员特点","１：慷慨大方。（例如，小费大手，及时雨，慈善家）","２：善待动物。（例如，爱猫人士，农场出生，与马同舞）","３：梦想家。（例如，惯常异想天开，预言家，创造者）","４：享乐主义者。（例如，派对大师，酒吧醉汉，“放纵到死”）","５：赌徒，冒险家。（例如，扑克脸，任何事都来一遍，活在生死边缘）","６：好厨子，好吃货。（例如，烤得一手好蛋糕，无米之炊都能做好，优雅的食神）","７：女人缘/万人迷。（例如，长袖善舞，甜言蜜语，电眼乱放）","８：忠心在我。（例如，背负自己的朋友，从未破誓，为信念而死）","９：好名头。（例如，村里最好的饭后聊天人士，虔信圣徒，不惧任何危险）","１０：雄心壮志。（例如，梦想远大，目标是成为ＢＯＳＳ，渴求一切）"},
		{"即时症状","1) 失忆 ：调查员会发现自己只记得最后身处的安全地点，却没有任何来到这里的记忆。例如，调查员前一刻还在家中吃着早饭，下一刻就已经直面着不知名的怪物。这将会持续 1D10 轮。","2) 假性残疾 ：调查员陷入了心理性的失明，失聪以及躯体缺失感中，持续 1D10 轮。","3) 暴力倾向 ：调查员陷入了六亲不认的暴力行为中，对周围的敌人与友方进行着无差别的攻击，持续 1D10 轮。","4) 偏执：调查员陷入了严重的偏执妄想之中，持续１Ｄ１０轮。有人在暗中窥视着他们，同伴中有人背叛了他们，没有人可以信任，万事皆虚。","5) 人际依赖：守秘人适当参考调查员的背景中重要之人的条目，调查员因为一些原因而将他人误认为了他重要的人并且努力的会与那个人保持那种关系，持续 1D10 轮","6) 昏厥：调查员当场昏倒，并需要 1D10 轮才能苏醒。.","7) 逃避行为：调查员会用任何的手段试图逃离现在所处的位置，即使这意味着开走唯一一辆交通工具并将其它人抛诸脑后，调查员会试图逃离 1D10轮。","8) 竭嘶底里：调查员表现出大笑，哭泣，嘶吼，害怕等的极端情绪表现，持续 1D10 轮。","9) 恐惧：调查员投一个 D100 或者由守秘人选择，来从恐惧症状表中选择一个恐惧源，就算这一恐惧的事物是并不存在的，调查员的症状会持续 1D10轮。","10) 狂躁 ：调查员投一个 D100 或者由守秘人选择，来从狂躁症状表中选择一个狂躁的诱因，这个症状将会持续 1D10 轮。"},
		{"总结症状","1) 失忆（Amnesia）：回过神来，调查员们发现自己身处一个陌生的地方，并忘记了自己是谁。记忆会随时间恢复。","2) 被窃（Robbed）：调查员在 1D10 小时后恢复清醒，发觉自己被盗，身体毫发无损。如果调查员携带着宝贵之物（见调查员背景），做幸运检定来决定其是否被盗。所有有价值的东西无需检定自动消失。","3) 遍体鳞伤（Battered）：调查员在 1D10 小时后恢复清醒，发现自己身上满是拳痕和瘀伤。生命值减少到疯狂前的一半，但这不会造成重伤。调查员没有被窃。这种伤害如何持续到现在由守秘人决定。","4) 暴力倾向（Violence）：调查员陷入强烈的暴力与破坏欲之中。调查员回过神来可能会理解自己做了什么也可能毫无印象。调查员对谁或何物施以暴力，他们是杀人还是仅仅造成了伤害，由守秘人决定。","5) 极端信念（Ideology/Beliefs）：查看调查员背景中的思想信念，调查员会采取极端和疯狂的表现手段展示他们的思想信念之一。比如一个信教者会在地铁上高声布道。","6) 重要之人（Significant People）：考虑调查员背景中的重要之人，及其重要的原因。在 1D10 小时或更久的时间中，调查员将不顾一切地接近那个人，并为他们之间的关系做出行动。","7) 被收容（Institutionalized）：调查员在精神病院病房或警察局牢房中回过神来，他们可能会慢慢回想起导致自己被关在这里的事情。","8) 逃避行为（Flee in panic）：调查员恢复清醒时发现自己在很远的地方，也许迷失在荒郊野岭，或是在驶向远方的列车或长途汽车上。","9) 恐惧（Phobia）：调查员患上一个新的恐惧症。在表Ⅸ：恐惧症状表上骰 1 个 D100 来决定症状，或由守秘人选择一个。调查员在 1D10 小时后回过神来，并开始为避开恐惧源而采取任何措施。","10) 狂躁（Mania）：调查员患上一个新的狂躁症。在表Ⅹ：狂躁症状表上骰 1 个 d100 来决定症状，或由守秘人选择一个。调查员会在 1d10 小时后恢复理智。在这次疯狂发作中，调查员将完全沉浸于其新的狂躁症状。这症状是否会表现给旁人则取决于守秘人和此调查员。"},
		{"恐惧症状","1) 洗澡恐惧症（Ablutophobia）：对于洗涤或洗澡的恐惧。","2) 恐高症（Acrophobia）：对于身处高处的恐惧。","3) 飞行恐惧症（Aerophobia）：对飞行的恐惧。","4) 广场恐惧症（Agoraphobia）：对于开放的（拥挤）公共场所的恐惧。","5) 恐鸡症（Alektorophobia）：对鸡的恐惧。","6) 大蒜恐惧症（Alliumphobia）：对大蒜的恐惧。","7) 乘车恐惧症（Amaxophobia）：对于乘坐地面载具的恐惧。","8) 恐风症（Ancraophobia）：对风的恐惧。","9) 男性恐惧症（Androphobia）：对于成年男性的恐惧。","10) 恐英症（Anglophobia）：对英格兰或英格兰文化的恐惧。","11) 恐花症（Anthophobia）：对花的恐惧。","12) 截肢者恐惧症（Apotemnophobia）：对截肢者的恐惧。","13) 蜘蛛恐惧症（Arachnophobia）：对蜘蛛的恐惧。","14) 闪电恐惧症（Astraphobia）：对闪电的恐惧。","15) 废墟恐惧症（Atephobia）：对遗迹或残址的恐惧。","16) 长笛恐惧症（Aulophobia）：对长笛的恐惧。","17) 细菌恐惧症（Bacteriophobia）：对细菌的恐惧。","18) 导弹/子弹恐惧症（Ballistophobia）：对导弹或子弹的恐惧。","19) 跌落恐惧症（Basophobia）：对于跌倒或摔落的恐惧。","20) 书籍恐惧症（Bibliophobia）：对书籍的恐惧。","21) 植物恐惧症（Botanophobia）：对植物的恐惧。","22) 美女恐惧症（Caligynephobia）：对美貌女性的恐惧。","23) 寒冷恐惧症（Cheimaphobia）：对寒冷的恐惧。","24) 恐钟表症（Chronomentrophobia）：对于钟表的恐惧。","25) 幽闭恐惧症（Claustrophobia）：对于处在封闭的空间中的恐惧。","26) 小丑恐惧症（Coulrophobia）：对小丑的恐惧。","27) 恐犬症（Cynophobia）：对狗的恐惧。","28) 恶魔恐惧症（Demonophobia）：对邪灵或恶魔的恐惧。","29) 人群恐惧症（Demophobia）：对人群的恐惧。","30) 牙科恐惧症①（Dentophobia）：对牙医的恐惧。","31) 丢弃恐惧症（Disposophobia）：对于丢弃物件的恐惧（贮藏癖）。","32) 皮毛恐惧症（Doraphobia）：对动物皮毛的恐惧。","33) 过马路恐惧症（Dromophobia）：对于过马路的恐惧。","34) 教堂恐惧症（Ecclesiophobia）：对教堂的恐惧。","35) 镜子恐惧症（Eisoptrophobia）：对镜子的恐惧。","36) 针尖恐惧症（Enetophobia）：对针或大头针的恐惧。","37) 昆虫恐惧症（Entomophobia）：对昆虫的恐惧。","38) 恐猫症（Felinophobia）：对猫的恐惧。","39) 过桥恐惧症（Gephyrophobia）：对于过桥的恐惧。","40) 恐老症（Gerontophobia）：对于老年人或变老的恐惧。","41) 恐女症（Gynophobia）：对女性的恐惧。","42) 恐血症（Haemaphobia）：对血的恐惧。","43) 宗教罪行恐惧症（Hamartophobia）：对宗教罪行的恐惧。","44) 触摸恐惧症（Haphophobia）：对于被触摸的恐惧。","45) 爬虫恐惧症（Herpetophobia）：对爬行动物的恐惧。","46) 迷雾恐惧症（Homichlophobia）：对雾的恐惧。","47) 火器恐惧症（Hoplophobia）：对火器的恐惧。","48) 恐水症（Hydrophobia）：对水的恐惧。","49) 催眠恐惧症①（Hypnophobia）：对于睡眠或被催眠的恐惧。","50) 白袍恐惧症（Iatrophobia）：对医生的恐惧。","51) 鱼类恐惧症（Ichthyophobia）：对鱼的恐惧。","52) 蟑螂恐惧症（Katsaridaphobia）：对蟑螂的恐惧。","53) 雷鸣恐惧症（Keraunophobia）：对雷声的恐惧。","54) 蔬菜恐惧症（Lachanophobia）：对蔬菜的恐惧。","55) 噪音恐惧症（Ligyrophobia）：对刺耳噪音的恐惧。","56) 恐湖症（Limnophobia）：对湖泊的恐惧。","57) 机械恐惧症（Mechanophobia）：对机器或机械的恐惧。","58) 巨物恐惧症（Megalophobia）：对于庞大物件的恐惧。","59) 捆绑恐惧症（Merinthophobia）：对于被捆绑或紧缚的恐惧。","60) 流星恐惧症（Meteorophobia）：对流星或陨石的恐惧。","61) 孤独恐惧症（Monophobia）：对于一人独处的恐惧。","62) 不洁恐惧症（Mysophobia）：对污垢或污染的恐惧。","63) 黏液恐惧症（Myxophobia）：对黏液（史莱姆）的恐惧。","64) 尸体恐惧症（Necrophobia）：对尸体的恐惧。","65) 数字 8 恐惧症（Octophobia）：对数字 8 的恐惧。","66) 恐牙症（Odontophobia）：对牙齿的恐惧。","67) 恐梦症（Oneirophobia）：对梦境的恐惧。","68) 称呼恐惧症（Onomatophobia）：对于特定词语的恐惧。","69) 恐蛇症（Ophidiophobia）：对蛇的恐惧。","70) 恐鸟症（Ornithophobia）：对鸟的恐惧。","71) 寄生虫恐惧症（Parasitophobia）：对寄生虫的恐惧。","72) 人偶恐惧症（Pediophobia）：对人偶的恐惧。","73) 吞咽恐惧症（Phagophobia）：对于吞咽或被吞咽的恐惧。","74) 药物恐惧症（Pharmacophobia）：对药物的恐惧。","75) 幽灵恐惧症（Phasmophobia）：对鬼魂的恐惧。","76) 日光恐惧症（Phenogophobia）：对日光的恐惧。","77) 胡须恐惧症（Pogonophobia）：对胡须的恐惧。","78) 河流恐惧症（Potamophobia）：对河流的恐惧。","79) 酒精恐惧症（Potophobia）：对酒或酒精的恐惧。","80) 恐火症（Pyrophobia）：对火的恐惧。","81) 魔法恐惧症（Rhabdophobia）：对魔法的恐惧。","82) 黑暗恐惧症（Scotophobia）：对黑暗或夜晚的恐惧。","83) 恐月症（Selenophobia）：对月亮的恐惧。","84) 火车恐惧症（Siderodromophobia）：对于乘坐火车出行的恐惧。","85) 恐星症（Siderophobia）：对星星的恐惧。","86) 狭室恐惧症（Stenophobia）：对狭小物件或地点的恐惧。","87) 对称恐惧症（Symmetrophobia）：对对称的恐惧。","88) 活埋恐惧症（Taphephobia）：对于被活埋或墓地的恐惧。","89) 公牛恐惧症（Taurophobia）：对公牛的恐惧。","90) 电话恐惧症（Telephonophobia）：对电话的恐惧。","91) 怪物恐惧症①（Teratophobia）：对怪物的恐惧。","92) 深海恐惧症（Thalassophobia）：对海洋的恐惧。","93) 手术恐惧症（Tomophobia）：对外科手术的恐惧。","94) 十三恐惧症（Triskadekaphobia）：对数字 13 的恐惧症。","95) 衣物恐惧症（Vestiphobia）：对衣物的恐惧。","96) 女巫恐惧症（Wiccaphobia）：对女巫与巫术的恐惧。","97) 黄色恐惧症（Xanthophobia）：对黄色或“黄”字的恐惧。","98) 外语恐惧症（Xenoglossophobia）：对外语的恐惧。","99) 异域恐惧症（Xenophobia）：对陌生人或外国人的恐惧。","100) 动物恐惧症（Zoophobia）：对动物的恐惧。"},
		{"狂躁症状","1) 沐浴癖（Ablutomania）：执着于清洗自己。","2) 犹豫癖（Aboulomania）：病态地犹豫不定。","3) 喜暗狂（Achluomania）：对黑暗的过度热爱。","4) 喜高狂（Acromaniaheights）：狂热迷恋高处。","5) 亲切癖（Agathomania）：病态地对他人友好。","6) 喜旷症（Agromania）：强烈地倾向于待在开阔空间中。","7) 喜尖狂（Aichmomania）：痴迷于尖锐或锋利的物体。","8) 恋猫狂（Ailuromania）：近乎病态地对猫友善。","9) 疼痛癖（Algomania）：痴迷于疼痛。","10) 喜蒜狂（Alliomania）：痴迷于大蒜。","11) 乘车癖（Amaxomania）：痴迷于乘坐车辆。","12) 欣快癖（Amenomania）：不正常地感到喜悦。","13) 喜花狂（Anthomania）：痴迷于花朵。","14) 计算癖（Arithmomania）：狂热地痴迷于数字。","15) 消费癖（Asoticamania）：鲁莽冲动地消费。","16) 隐居癖*（Automania）：过度地热爱独自隐居。【英文原文是恋车癖】","17) 芭蕾癖（Balletmania）：痴迷于芭蕾舞。","18) 窃书癖（Biliokleptomania）：无法克制偷窃书籍的冲动。","19) 恋书狂（Bibliomania）：痴迷于书籍和/或阅读","20) 磨牙癖（Bruxomania）：无法克制磨牙的冲动。","21) 灵臆症（Cacodemomania）：病态地坚信自己已被一个邪恶的灵体占据。","22) 美貌狂（Callomania）：痴迷于自身的美貌。","23) 地图狂（Cartacoethes）：在何时何处都无法控制查阅地图的冲动。","24) 跳跃狂（Catapedamania）：痴迷于从高处跳下。","25) 喜冷症（Cheimatomania）：对寒冷或寒冷的物体的反常喜爱。","26) 舞蹈狂（Choreomania）：无法控制地起舞或发颤。","27) 恋床癖（Clinomania）：过度地热爱待在床上。","28) 恋墓狂（Coimetormania）：痴迷于墓地。","29) 色彩狂（Coloromania）：痴迷于某种颜色。","30) 小丑狂（Coulromania）：痴迷于小丑。","31) 恐惧狂（Countermania）：执着于经历恐怖的场面。","32) 杀戮癖（Dacnomania）：痴迷于杀戮。","33) 魔臆症（Demonomania）：病态地坚信自己已被恶魔附身。","34) 抓挠癖（Dermatillomania）：执着于抓挠自己的皮肤。","35) 正义狂（Dikemania）：痴迷于目睹正义被伸张。","36) 嗜酒狂（Dipsomania）：反常地渴求酒精。","37) 毛皮狂（Doramania）：痴迷于拥有毛皮。（存疑）","38) 赠物癖（Doromania）：痴迷于赠送礼物。","39) 漂泊症（Drapetomania）：执着于逃离。","40) 漫游癖（Ecdemiomania）：执着于四处漫游。","41) 自恋狂（Egomania）：近乎病态地以自我为中心或自我崇拜。","42) 职业狂（Empleomania）：对于工作的无尽病态渴求。","43) 臆罪症（Enosimania）：病态地坚信自己带有罪孽。","44) 学识狂（Epistemomania）：痴迷于获取学识。","45) 静止癖（Eremiomania）：执着于保持安静。","46) 乙醚上瘾（Etheromania）：渴求乙醚。","47) 求婚狂（Gamomania）：痴迷于进行奇特的求婚。","48) 狂笑癖（Geliomania）：无法自制地，强迫性的大笑。","49) 巫术狂（Goetomania）：痴迷于女巫与巫术。","50) 写作癖（Graphomania）：痴迷于将每一件事写下来。","51) 裸体狂（Gymnomania）：执着于裸露身体。","52) 妄想狂（Habromania）：近乎病态地充满愉快的妄想（而不顾现实状况如何）。","53) 蠕虫狂（Helminthomania）：过度地喜爱蠕虫。","54) 枪械狂（Hoplomania）：痴迷于火器。","55) 饮水狂（Hydromania）：反常地渴求水分。","56) 喜鱼癖（Ichthyomania）：痴迷于鱼类。","57) 图标狂（Iconomania）：痴迷于图标与肖像","58) 偶像狂（Idolomania）：痴迷于甚至愿献身于某个偶像。","59) 信息狂（Infomania）：痴迷于积累各种信息与资讯。","60) 射击狂（Klazomania）：反常地执着于射击。","61) 偷窃癖（Kleptomania）：反常地执着于偷窃。","62) 噪音癖（Ligyromania）：无法自制地执着于制造响亮或刺耳的噪音。","63) 喜线癖（Linonomania）：痴迷于线绳。","64) 彩票狂（Lotterymania）：极端地执着于购买彩票。","65) 抑郁症（Lypemania）：近乎病态的重度抑郁倾向。","66) 巨石狂（Megalithomania）：当站在石环中或立起的巨石旁时，就会近乎病态地写出各种奇怪的创意。","67) 旋律狂（Melomania）：痴迷于音乐或一段特定的旋律。","68) 作诗癖（Metromania）：无法抑制地想要不停作诗。","69) 憎恨癖（Misomania）：憎恨一切事物，痴迷于憎恨某个事物或团体。","70) 偏执狂（Monomania）：近乎病态地痴迷与专注某个特定的想法或创意。","71) 夸大癖（Mythomania）：以一种近乎病态的程度说谎或夸大事物。","72) 臆想症（Nosomania）：妄想自己正在被某种臆想出的疾病折磨。","73) 记录癖（Notomania）：执着于记录一切事物（例如摄影）","74) 恋名狂（Onomamania）：痴迷于名字（人物的、地点的、事物的）","75) 称名癖（Onomatomania）：无法抑制地不断重复某个词语的冲动。","76) 剔指癖（Onychotillomania）：执着于剔指甲。","77) 恋食癖（Opsomania）：对某种食物的病态热爱。","78) 抱怨癖（Paramania）：一种在抱怨时产生的近乎病态的愉悦感。","79) 面具狂（Personamania）：执着于佩戴面具。","80) 幽灵狂（Phasmomania）：痴迷于幽灵。","81) 谋杀癖（Phonomania）：病态的谋杀倾向。","82) 渴光癖（Photomania）：对光的病态渴求。","83) 背德癖（Planomania）：病态地渴求违背社会道德【原文是漂泊症】","84) 求财癖（Plutomania）：对财富的强迫性的渴望。","85) 欺骗狂（Pseudomania）：无法抑制的执着于撒谎。","86) 纵火狂（Pyromania）：执着于纵火。","87) 提问狂（Questiong-Asking Mania）：执着于提问。","88) 挖鼻癖（Rhinotillexomania）：执着于挖鼻子。","89) 涂鸦癖（Scribbleomania）：沉迷于涂鸦。","90) 列车狂（Siderodromomania）：认为火车或类似的依靠轨道交通的旅行方式充满魅力。","91) 臆智症（Sophomania）：臆想自己拥有难以置信的智慧。","92) 科技狂（Technomania）：痴迷于新的科技。","93) 臆咒狂（Thanatomania）：坚信自己已被某种死亡魔法所诅咒。","94) 臆神狂（Theomania）：坚信自己是一位神灵。","95) 抓挠癖（Titillomaniac）：抓挠自己的强迫倾向。","96) 手术狂（Tomomania）：对进行手术的不正常爱好。","97) 拔毛癖（Trichotillomania）：执着于拔下自己的头发。","98) 臆盲症（Typhlomania）：病理性的失明。","99) 嗜外狂（Xenomania）：痴迷于异国的事物。","100) 喜兽癖（Zoomania）：对待动物的态度近乎疯狂地友好。"},
		{"阵营","守序善良","中立善良","混乱善良","守序中立","绝对中立","混乱中立","守序邪恶","中立邪恶","混乱邪恶"},
		{"哈罗花色","锤-力量","钥-敏捷","盾-体质","书-智力","星-感知","冠-魅力"},
		{"冒险点子","1 盗贼偷走了王冠珠宝。","2 一头龙来到城镇要求贡品。","3 发现一座古代法师的墓穴。","4 富商们在家中遇害。","5 城中广场雕像竟是一个被石化的圣武士。","6 载有重要货品的商队正要经过某个危险区域。","7 狂热教徒绑架活人作为祭品。","8 地精大肆攻击村庄。","9 山贼与兽人结伙。","10 某个暗黑卫士在某地组织怪物。","11 低层界的通道被打开，出现许多恶魔。","12 本来被封锁的矿坑突然冒出许多怪东西。","13 法师公会公开反对地方议会。","14 人类和精灵发生冲突。","15 城镇的迷雾中出现幽魂。","16 某位高阶牧师的圣徽遗失了。","17 某个邪恶法师发明了新型魔像。","18 城镇中出现狼人。","19 奴隶贩子不断侵袭村落。","20 火元素从法师实验室中逃脱。","21 食人魔占据桥头收取过路费。","22 复制分身镜复制出某个英雄的邪恶分身。","23 两群兽人部落发生恶斗。","24 发现一座新的地下墓穴。","25 邻国发动侵略。","26 两个知名的英雄彼此决斗。","27 为了打败某个怪物，必须找到一把古剑。","28 为了避免某个灾难预言成真，必须找到一个古神器。","29 食人魔绑走了市长的女儿。","30 某个法师连同强力魔法物品一起被埋在充满陷阱的墓穴。","31 某个附魔师诱使他人行窃。","32 某个变形的夺心魔聚集控制了许多奴仆。","33 鼠人导致社群发生瘟疫。","34 解开法师塔所有魔法陷阱的钥匙遗失了。","35 沙华鱼人攻击沿岸村落。","36 盗墓者在墓园中发现一座充满食尸鬼的大墓穴。","37 某个法师需要某种只能在丛林深处找到的魔法材料。","38 找到一张地图，上面标示了远古魔法熔炉的位置。","39 城市下水道中常出现怪物袭击居民。","40 一名外交官身陷敌国需要救援。","41 小城中出现吸血鬼。","42 传言某座闹鬼的高塔内有许多宝藏。","43 野蛮人大举侵略村庄。","44 巨人偷走农村的牲畜。","45 不明雪暴将冬狼引入和平之地。","46 唯一的山路被斯芬克司阻挡，谁都无法过。","47 邪恶佣兵团在村落附近建立据点。","48 公爵中了魔法毒素，必须找到解毒剂。","49 某个德鲁伊需要帮手抵御地精的侵袭。","50 神秘的古代诅咒将无辜者变为杀人魔。","51 石像鬼与巨鹰在山区集体恶斗。","52 神秘商人将假的魔法物品卖至城内，然后溜走。","53 最近发现的某神器使得奥术都无法施展。","54 某邪恶贵族悬赏刺杀另一名善良贵族。","55 探索地下城的冒险队在一周后仍未回来。","56 某个善良战士的葬礼遭其生前敌人扰乱。","57 超巨型虫类生物在沙漠中袭击居留地。","58 邪恶暴君禁止他人使用魔法。","59 对魔法免疫的大型凶暴狼在森林中聚集狼群。","60 侏儒聚落造了一艘飞船。","61 某座湖中岛屿其实是沈没森林的顶端。","62 世界之树底下埋着时光大钟。","63 某个孩童因迷路进入大墓地，而且即将入夜。","64 地下城市中的矮人全部消失。","65 神秘废墟的洞窟冒出奇怪绿烟。","66 闹鬼的森林在夜晚传出怪声。","67 贼群偷走一大笔宝藏，躲到“魔邓肯豪宅”中。","68 某术士想进行灵界旅行，但却消失无踪。","69 圣武士须进行一项赎罪任务，召集帮手进入巨魔巢穴。","70 某王国的法师准备开战。","71 高阶牧师是个幻象。","72 新来的贵族想清除某片野地上的怪物。","73 一个鲨蜥兽破坏农地。","74 蛇人族为了逃避疫病而移居至城市附近。","75 森林中的树人受到无名大火的威胁。","76 牧师将某个英雄复活，却发现他和想象中不同。","77 悲伤的吟游诗人在旅店中讲述他朋友遭囚禁的故事。","78 邪恶贵族设立一个冒险者公会，以监督各个冒险者。","79 半身人商队想经过一个充满掘地虫的区域。","80 王宫中所有门都突然上了魔法锁或附有火焰陷阱。","81 某个无辜的死刑犯要求救援。","82 某强大法师的墓穴有许多魔法物品，却沉在沼泽中。","83 大篷车队在赶路时突然遭到破坏。","84 某种只在偏僻村落中才有的青蛙，突然大量落在大城中。","85 某个嫉妒的情敌想破坏一场婚礼。","86 某个消失多年的女子突然被发现在湖上行走。","87 一场地震掩埋了刚发现的地下城。","88 一名被中伤的半精灵请求勇士为她与人决斗。","89 暴风中心有一座空中城堡。","90 人们对市场上叫卖金龙躯体的半兽人商人感到怀疑。","91 某个粗心的法师将惊异权杖给错了人。","92 不死生物幽影在大图书馆中徘徊，尤其是某个废弃已久的储藏室。","93 城中某个空屋的大门，突然变成时空隧道。","94 海盗与怪物结盟，在河上收取高额过路费。","95 某件魔法物品分成三份，敌人手中握有两份，另一份则遗失。","96 翼龙成群袭击羊群和牧羊人。","97 邪恶牧师秘密集会召唤邪恶神祇。","98 大城市遭到人类、灰矮人和豺狼人围攻。","99 传说某个古修道院遗迹中有个巨大的宝石。","100 蜥人族佣兵群待价而沽。"},
		{"麻将","一万","一索","一筒","二万","二索","二筒","三万","三索","三筒","四万","四索","四筒","赤五万","赤五索","赤五筒","六万","六索","六筒","七万","七索","七筒","八万","八索","八筒","九万","九索","九筒","东","南","西","北","中","发","白","一万","一索","一筒","二万","二索","二筒","三万","三索","三筒","四万","四索","四筒","五万","五索","五筒","六万","六索","六筒","七万","七索","七筒","八万","八索","八筒","九万","九索","九筒","东","南","西","北","中","发","白","一万","一索","一筒","二万","二索","二筒","三万","三索","三筒","四万","四索","四筒","五万","五索","五筒","六万","六索","六筒","七万","七索","七筒","八万","八索","八筒","九万","九索","九筒","东","南","西","北","中","发","白","一万","一索","一筒","二万","二索","二筒","三万","三索","三筒","四万","四索","四筒","五万","五索","五筒","六万","六索","六筒","七万","七索","七筒","八万","八索","八筒","九万","九索","九筒","东","南","西","北","中","发","白"},
		{"扑克花色","红桃","黑桃","方片","梅花"},
		{"扑克","红桃A","红桃2","红桃3","红桃4","红桃5","红桃6","红桃7","红桃8","红桃9","红桃10","红桃J","红桃Q","红桃K","黑桃A","黑桃2","黑桃3","黑桃4","黑桃5","黑桃6","黑桃7","黑桃8","黑桃9","黑桃10","黑桃J","黑桃Q","黑桃K","方片A","方片2","方片3","方片4","方片5","方片6","方片7","方片8","方片9","方片10","方片J","方片Q","方片K","梅花A","梅花2","梅花3","梅花4","梅花5","梅花6","梅花7","梅花8","梅花9","梅花10","梅花J","梅花Q","梅花K","大王","小王"},
		{"塔罗牌","【0】愚者（The Fool，0)","【1】魔术师（The Magician，I)","【2】女祭司（The High Priestess，II)","【3】女皇（The Empress，III)","【4】皇帝（The Emperor，IV)","【5】教皇（The Hierophant，or the Pope，V)","【6】恋人（The Lovers，VI)","【7】战车（The Chariot，VII)","【8】力量（Strength，VIII）","【9】隐者（The Hermit，IX)","【10】命运之轮（The Wheel of Fortune，X)","【11】正义（Justice，XI）","【12】倒吊人（The Hanged Man，XII)","【13】 死神（Death，XIII)","【14】节制（Temperance，XIV)","【15】恶魔（The Devil ，XV)","【16】塔（The Tower，XVI)","【17】星星（The Star，XVII)","【18】月亮（The Moon，XVIII)","【19】太阳（The Sun，XIX)","【20】审判（Judgement，XX)","【21】世界（The World，XXI)"},
		{"塔罗牌占卜","【0】愚者（The Fool，0)正位:\n憧憬自然的地方、毫无目的地前行、喜欢尝试挑战新鲜事物、四处流浪。明知是毫无意义的冒险，错误的选择及失败的结果，却一意孤行，盲目地追求梦想而完全忽略现实；好冒险、寻梦人、不拘泥于传统的观念、自由奔放、一切从基础出发、四处流浪。自由恋爱、不顾及他人看法、以独特的方式获得成功、轻易坠入爱河、浪漫多彩的爱情、独特的恋人、等待交往机会。工作上具冒险心、追求新奇。热衷于事业或学业、以独特的方式取得意外的收获、由于好奇心对当前的学业产生浓厚的兴趣、把握重点、寻求捷径、倾向于自由的工作氛围、适合艺术类工作或从事自由职业。健康状况佳。旅行有意外收获。美好的梦想。","【0】愚者（The Fool，0)逆位:\n冒险的行动，追求可能性，重视梦想，无视物质的损失，离开家园，过于信赖别人，为出外旅行而烦恼。心情空虚、轻率的恋情、无法长久持续的融洽感、不安的爱情的旅程、对婚姻感到束缚、彼此忽冷忽热、不顾众人反对坠入爱河、为恋人的负心所伤、感情不专一。","【1】魔术师（The Magician，I)正位:\n事情的开始，行动的改变，熟练的技术及技巧，贯彻我的意志，运用自然的力量来达到野心。","【1】魔术师（The Magician，I)逆位:\n意志力薄弱，起头难，走入错误的方向，知识不足，被骗和失败。","【2】女祭司（The High Priestess，II)正位:\n开发出内在的神秘潜力，前途将有所变化的预言，深刻地思考，敏锐的洞察力，准确的直觉。","【2】女祭司（The High Priestess，II)逆位:\n过于洁癖，无知，贪心，目光短浅，自尊心过高，偏差的判断，有勇无谋，自命不凡。","【3】女皇（The Empress，III)正位:\n幸福，成功，收获，无忧无虑，圆满的家庭生活，良好的环境，美貌，艺术，与大自然接触，愉快的旅行，休闲。","【3】女皇（The Empress，III)逆位:\n不活泼，缺乏上进心，散漫的生活习惯，无法解决的事情，不能看到成果，担于享乐，环境险恶，与家人发生纠纷。","【4】皇帝（The Emperor，IV)正位:\n光荣，权力，胜利，握有领导权，坚强的意志，达成目标，父亲的责任，精神上的孤单。","【4】皇帝（The Emperor，IV)逆位:\n幼稚，无力，独裁，撒娇任性，平凡，没有自信，行动力不足，意志薄弱，被支配。","【5】教皇（The Hierophant，or the Pope，V)正位:\n援助，同情，宽宏大量，可信任的人给予的劝告，良好的商量对象，得到精神上的满足，遵守规则，志愿者。","【5】教皇（The Hierophant，or the Pope，V)逆位:\n错误的讯息，恶意的规劝，上当，援助被中断，愿望无法达成，被人利用，被放弃。","【6】恋人（The Lovers，VI)正位:\n撮合，爱情，流行，兴趣，充满希望的未来，魅力，增加朋友。","【6】恋人（The Lovers，VI)逆位:\n禁不起诱惑，纵欲过度，反覆无常，友情变淡，厌倦，争吵，华丽的打扮，优柔寡断。","【7】战车（The Chariot，VII)正位:\n努力而获得成功，胜利，克服障碍，行动力，自立，尝试，自我主张，年轻男子，交通工具，旅行运大吉。","【7】战车（The Chariot，VII)逆位:\n争论失败，发生纠纷，阻滞，违返规则，诉诸暴力，顽固的男子，突然的失败，不良少年，挫折和自私自利。","【8】力量（Strength，VIII）正位:\n大胆的行动，有勇气的决断，新发展，大转机，异动，以意志力战胜困难，健壮的女人。","【8】力量（Strength，VIII）逆位:\n胆小，输给强者，经不起诱惑，屈服在权威与常识之下，没有实践便告放弃，虚荣，懦弱，没有耐性。","【9】隐者（The Hermit，IX)正位:\n隐藏的事实，个别的行动，倾听他人的意见，享受孤独，自己的丢化，有益的警戒，年长者，避开危险，祖父，乡间生活。","【9】隐者（The Hermit，IX)逆位:\n无视警，憎恨孤独，自卑，担心，幼稚思想，过于慎重导致失败，偏差，不宜旅行。","【10】命运之轮（The Wheel of Fortune，X)正位:\n关键性的事件，有新的机会，因的潮流，环境的变化，幸运的开端，状况好转，问题解决，幸运之神降临。","【10】命运之轮（The Wheel of Fortune，X)逆位:\n边疆的不行，挫折，计划泡汤，障碍，无法修正方向，往坏处发展，恶性循环，中断。","【11】正义（Justice，XI）正位:\n公正、中立、诚实、心胸坦荡、表里如一、身兼二职、追求合理化、协调者、与法律有关、光明正大的交往、感情和睦。","【11】正义（Justice，XI）逆位:\n失衡、偏见、纷扰、诉讼、独断专行、问心有愧、无法两全、表里不一、男女性格不合、情感波折、无视社会道德的恋情。","【12】倒吊人（The Hanged Man，XII)正位:\n接受考验、行动受限、牺牲、不畏艰辛、不受利诱、有失必有得、吸取经验教训、浴火重生、广泛学习、奉献的爱。","【12】倒吊人（The Hanged Man，XII)逆位:\n无谓的牺牲、骨折、厄运、不够努力、处于劣势、任性、利己主义者、缺乏耐心、受惩罚、逃避爱情、没有结果的恋情。","【13】死神（Death，XIII)正位:\n失败、接近毁灭、生病、失业、维持停滞状态、持续的损害、交易停止、枯燥的生活、别离、重新开始、双方有很深的鸿沟、恋情终止。","【13】死神（Death，XIII)逆位:\n抱有一线希望、起死回生、回心转意、摆脱低迷状态、挽回名誉、身体康复、突然改变计划、逃避现实、斩断情丝、与旧情人相逢。","【14】节制（Temperance，XIV)正位:\n单纯、调整、平顺、互惠互利、好感转为爱意、纯爱、深爱。","【14】节制（Temperance，XIV)逆位:\n消耗、下降、疲劳、损失、不安、不融洽、爱情的配合度不佳。","【15】恶魔（The Devil ，XV)正位:\n被束缚、堕落、生病、恶意、屈服、欲望的俘虏、不可抗拒的诱惑、颓废的生活、举债度日、不可告人的秘密、私密恋情。","【15】恶魔（The Devil ，XV)逆位:\n逃离拘束、解除困扰、治愈病痛、告别过去、暂停、别离、拒绝诱惑、舍弃私欲、别离时刻、爱恨交加的恋情。","【16】塔（The Tower，XVI)正位:\n破产、逆境、被开除、急病、致命的打击、巨大的变动、受牵连、信念崩溃、玩火自焚、纷扰不断、突然分离，破灭的爱。","【16】塔（The Tower，XVI)逆位:\n困境、内讧、紧迫的状态、状况不佳、趋于稳定、骄傲自大将付出代价、背水一战、分离的预感、爱情危机。","【17】星星（The Star，XVII)正位:\n前途光明、充满希望、想象力、创造力、幻想、满足愿望、水准提高、理想的对象、美好的恋情。","【17】星星（The Star，XVII)逆位:\n挫折、失望、好高骛远、异想天开、仓皇失措、事与愿违、工作不顺心、情况悲观、秘密恋情、缺少爱的生活。","【18】月亮（The Moon，XVIII)正位:\n不安、迷惑、动摇、谎言、欺骗、鬼迷心窍、动荡的爱、三角关系。","【18】月亮（The Moon，XVIII)逆位:\n逃脱骗局、解除误会、状况好转、预知危险、等待、正视爱情的裂缝。","【19】太阳（The Sun，XIX)正位:\n活跃、丰富的生命力、充满生机、精力充沛、工作顺利、贵人相助、幸福的婚姻、健康的交际。","【19】太阳（The Sun，XIX)逆位:\n消沉、体力不佳、缺乏连续性、意气消沉、生活不安、人际关系不好、感情波动、离婚。","【20】审判（Judgement，XX)正位:\n复活的喜悦、康复、坦白、好消息、好运气、初露锋芒、复苏的爱、重逢、爱的奇迹。","【20】审判（Judgement，XX)逆位:\n一蹶不振、幻灭、隐瞒、坏消息、无法决定、缺少目标、没有进展、消除、恋恋不舍。","【21】世界（The World，XXI)正位:\n完成、成功、完美无缺、连续不断、精神亢奋、拥有毕生奋斗的目标、完成使命、幸运降临、快乐的结束、模范情侣。","【21】世界（The World，XXI)逆位:\n未完成、失败、准备不足、盲目接受、一时不顺利、半途而废、精神颓废、饱和状态、合谋、态度不够融洽、感情受挫。"},
		
	};
	int findDeck(std::string strDeckName) {
		int index = PublicDeck.size();
		do{
			if (PublicDeck[--index][0] == strDeckName) {
				return index;
			}
		}while(index);
		return -1;
	}
	std::string drawCard(std::vector<std::string> &TempDeck)
	{
		int ans = RandomGenerator::Randint(0, TempDeck.size() - 1);
		std::string strReply(TempDeck[ans]);
		TempDeck.erase(TempDeck.begin()+ans);
		return strReply;
	}


}



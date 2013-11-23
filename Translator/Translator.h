const int MAX_NUM_WORDS=2000;
const int MAX_WORD_LEN=50;
class Dictionary
{
	public:
		Dictionary(const char dictionaryFileName[]);	//constructor - initiate Dictionary and read in from dictionary text file
		bool translateEngToElv(char wordOut[], const char wordIn[]); //compares an english word passed in, if found, returns elvish word
		bool translateElvToEng(char wordOut[], const char wordIn[]);	//compares an elvish word passed in, if found, returns english word
		void addWord(const char englishTempWord[], const char elvishTempWord[]);	//adds a word to the dictionary in alphabetical order by english
		void sortByElvish(void);	//sorts dictionary alphabetically by elvish word
	private:
		char english[MAX_NUM_WORDS][MAX_WORD_LEN];	//character array to store english words
		char elvish[MAX_NUM_WORDS][MAX_WORD_LEN];		//character array to store elvish words
		int numEntries;	//keep a count of the number of entries in the dictionary
		bool isSortedinElvish;	//check whether dictionary is already sorted in elvish before running sortByElvish function
};

class Translator
{
	public:
		Translator(const char dictionaryFileName[]);	//constructor that takes in a dictionary file name
		void toElvish(char elvishLineOut[], const char englishLineIn[]);	//takes in an english line, translates and sends out elvish line
		void toEnglish(char englishLineOut[], const char elvishLineIn[]);	//takes in an elvish line, translates and sends out english line
	private:
		Dictionary dict;	//variable dict of type Dictionary
};


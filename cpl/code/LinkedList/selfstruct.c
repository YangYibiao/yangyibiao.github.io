//struct SELF {
//  int a;
//  struct SELF b;
//  float c;
//};

struct SELF {
  int a;
  struct SELF b;
  float c;
};

//struct SELF {
//  int a;
//  struct SELF * b;
//  float c;
//};

typedef struct {
 int a;
 SELF * b;
 float c;
} SELF;

//typedef struct SELF_TAG {
//  int a;
//  struct SELF_TAG *b;
//  float c;
//} SELF;
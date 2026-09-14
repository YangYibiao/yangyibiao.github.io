//struct SELF {
//  int a;
//  struct SELF b;
//  float c;
//};

// struct SELF {
//   int a;
//   struct SELF b; // error: field ‘b’ recursively requires itself to be defined
//   float c;
// };

struct SELF {
 int a;
 struct SELF * b;
 float c;
};

// typedef struct {
//  int a;
//  SELF * b; // error: SELF undeclared (first use in this function)
//  float c;
// } SELF;

typedef struct SELF_TAG {
 int a;
 struct SELF_TAG *b;
 float c;
} SELF;
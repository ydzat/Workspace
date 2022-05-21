typedef enum us_type {US_TYPE_INT, US_TYPE_UINT, US_TYPE_DOUBLE, US_TYPE_STRING} us_type_t;
typedef enum us_change {US_ADD, US_REMOVE} us_ch_t;
typedef enum us_operation {US_OP_MERGE, US_OP_CUT, US_OP_DIFF} us_op_t;

struct uset;

struct uset *usetinit(void);
void         usetfree(struct uset *set);

int  usetch(struct uset *set, void *val, us_type_t type, us_ch_t op);
int  usetop(struct uset *s1, struct uset *s2, us_op_t op);
int  usetiter(struct uset* set, void **val, us_type_t *type, void *last);
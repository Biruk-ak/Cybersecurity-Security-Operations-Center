#ifndef SOC_DETECTION_RULES_RULE_EVAL_02_000_H
#define SOC_DETECTION_RULES_RULE_EVAL_02_000_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_RULE_EVAL_02_000_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_rule_eval_02_000_rec_t;

typedef struct { soc_rule_eval_02_000_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_rule_eval_02_000_db_t;

soc_rule_eval_02_000_db_t *soc_rule_eval_02_000_db_create(size_t n);
void soc_rule_eval_02_000_db_destroy(soc_rule_eval_02_000_db_t *db);
int soc_rule_eval_02_000_db_upsert(soc_rule_eval_02_000_db_t *db, const soc_rule_eval_02_000_rec_t *rec);
int soc_rule_eval_02_000_db_remove(soc_rule_eval_02_000_db_t *db, uint64_t id);
int soc_rule_eval_02_000_db_find(const soc_rule_eval_02_000_db_t *db, uint64_t id, soc_rule_eval_02_000_rec_t *out);
size_t soc_rule_eval_02_000_db_scan(const soc_rule_eval_02_000_db_t *db, uint32_t min_sev, soc_rule_eval_02_000_rec_t *out, size_t max);
uint64_t soc_rule_eval_02_000_hash(const void *p, size_t n);
int soc_rule_eval_02_000_validate(const soc_rule_eval_02_000_rec_t *rec);
int soc_rule_eval_02_000_to_json(const soc_rule_eval_02_000_rec_t *rec, char *buf, size_t len);
void soc_rule_eval_02_000_metrics(const soc_rule_eval_02_000_db_t *db, char *buf, size_t len);
int soc_rule_eval_02_000_correlate(soc_rule_eval_02_000_db_t *db, const soc_rule_eval_02_000_rec_t *seed, soc_rule_eval_02_000_rec_t *out, size_t max);
int soc_rule_eval_02_000_fn_000(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_001(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_002(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_003(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_004(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_005(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_006(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_007(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_008(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_009(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_010(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_011(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_012(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_013(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_014(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_015(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_016(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_017(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_018(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_019(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_020(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_021(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_022(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_023(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_024(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_025(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_026(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_027(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_028(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_029(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_030(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_031(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_032(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_033(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_034(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_035(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_036(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_037(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_038(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_039(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_040(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_041(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_042(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_043(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rule_eval_02_000_fn_044(soc_rule_eval_02_000_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_DETECTION_RULES_RULE_EVAL_02_000_H */

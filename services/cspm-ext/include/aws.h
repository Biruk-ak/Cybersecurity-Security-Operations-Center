#ifndef SOC_CSPM_EXT_AWS_H
#define SOC_CSPM_EXT_AWS_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_AWS_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_aws_rec_t;

typedef struct { soc_aws_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_aws_db_t;

soc_aws_db_t *soc_aws_db_create(size_t n);
void soc_aws_db_destroy(soc_aws_db_t *db);
int soc_aws_db_upsert(soc_aws_db_t *db, const soc_aws_rec_t *rec);
int soc_aws_db_remove(soc_aws_db_t *db, uint64_t id);
int soc_aws_db_find(const soc_aws_db_t *db, uint64_t id, soc_aws_rec_t *out);
size_t soc_aws_db_scan(const soc_aws_db_t *db, uint32_t min_sev, soc_aws_rec_t *out, size_t max);
uint64_t soc_aws_hash(const void *p, size_t n);
int soc_aws_validate(const soc_aws_rec_t *rec);
int soc_aws_to_json(const soc_aws_rec_t *rec, char *buf, size_t len);
void soc_aws_metrics(const soc_aws_db_t *db, char *buf, size_t len);
int soc_aws_correlate(soc_aws_db_t *db, const soc_aws_rec_t *seed, soc_aws_rec_t *out, size_t max);
int soc_aws_fn_000(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_001(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_002(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_003(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_004(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_005(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_006(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_007(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_008(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_009(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_010(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_011(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_012(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_013(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_014(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_015(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_016(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_017(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_018(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_019(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_020(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_021(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_022(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_023(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_024(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_025(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_026(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_027(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_028(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_029(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_030(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_031(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_032(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_033(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_034(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_035(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_036(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_037(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_038(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_039(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_040(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_041(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_042(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_043(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_044(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_045(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_046(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_047(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_048(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_049(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_050(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_051(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_052(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_053(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_054(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_055(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_056(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_057(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_058(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_059(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_060(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_061(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_062(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_063(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_064(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_065(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_066(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_067(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_068(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_069(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_070(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_071(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_072(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_073(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_074(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_075(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_076(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_077(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_078(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aws_fn_079(soc_aws_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_CSPM_EXT_AWS_H */

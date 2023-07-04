#ifndef UUID2411381439360
#define UUID2411381439360

/**
  * RandomForestClassifier(base_estimator=deprecated, bootstrap=True, ccp_alpha=0.0, class_name=RandomForestClassifier, class_weight=None, criterion=gini, estimator=DecisionTreeClassifier(), estimator_params=('criterion', 'max_depth', 'min_samples_split', 'min_samples_leaf', 'min_weight_fraction_leaf', 'max_features', 'max_leaf_nodes', 'min_impurity_decrease', 'random_state', 'ccp_alpha'), max_depth=20, max_features=sqrt, max_leaf_nodes=None, max_samples=None, min_impurity_decrease=0.0, min_samples_leaf=1, min_samples_split=2, min_weight_fraction_leaf=0.0, n_estimators=20, n_jobs=None, num_outputs=3, oob_score=False, package_name=everywhereml.sklearn.ensemble, random_state=None, template_folder=everywhereml/sklearn/ensemble, verbose=0, warm_start=False)
 */
class RandomForestClassifier {
    public:

        /**
         * Predict class from features
         */
        int predict(float *x) {
            int predictedValue = 0;
            size_t startedAt = micros();

            
                    
            uint16_t votes[3] = { 0 };
            uint8_t classIdx = 0;
            float classScore = 0;

            
                tree0(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree1(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree2(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree3(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree4(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree5(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree6(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree7(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree8(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree9(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree10(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree11(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree12(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree13(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree14(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree15(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree16(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree17(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree18(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree19(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            

            // return argmax of votes
            uint8_t maxClassIdx = 0;
            float maxVote = votes[0];

            for (uint8_t i = 1; i < 3; i++) {
                if (votes[i] > maxVote) {
                    maxClassIdx = i;
                    maxVote = votes[i];
                }
            }

            predictedValue = maxClassIdx;

                    

            latency = micros() - startedAt;

            return (lastPrediction = predictedValue);
        }

        
            

            /**
             * Predict class label
             */
            String predictLabel(float *x) {
                return getLabelOf(predict(x));
            }

            /**
             * Get label of last prediction
             */
            String getLabel() {
                return getLabelOf(lastPrediction);
            }

            /**
             * Get label of given class
             */
            String getLabelOf(int8_t idx) {
                switch (idx) {
                    case -1:
                        return "ERROR";
                    
                        case 0:
                            return "idling";
                    
                        case 1:
                            return "walking";
                    
                        case 2:
                            return "walking2";
                    
                    default:
                        return "UNKNOWN";
                }
            }


            /**
             * Get latency in micros
             */
            uint32_t latencyInMicros() {
                return latency;
            }

            /**
             * Get latency in millis
             */
            uint16_t latencyInMillis() {
                return latency / 1000;
            }
            

    protected:
        float latency = 0;
        int lastPrediction = 0;

        
            

        
            
                /**
                 * Random forest's tree #0
                 */
                void tree0(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[20] <= 0.7330456376075745) {
                            
                                
                        if (x[102] <= 0.5188425183296204) {
                            
                                
                        *classIdx = 0;
                        *classScore = 188.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 219.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[25] <= 0.2933156341314316) {
                            
                                
                        *classIdx = 2;
                        *classScore = 219.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 203.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #1
                 */
                void tree1(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[94] <= 35.5) {
                            
                                
                        if (x[4] <= 0.474151149392128) {
                            
                                
                        if (x[18] <= 3.248844623565674) {
                            
                                
                        *classIdx = 2;
                        *classScore = 221.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 191.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 191.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 198.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #2
                 */
                void tree2(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[108] <= 0.03809042042121291) {
                            
                                
                        *classIdx = 0;
                        *classScore = 214.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[41] <= 0.2931034415960312) {
                            
                                
                        if (x[87] <= 0.00027770276938099414) {
                            
                                
                        if (x[4] <= 0.4739435911178589) {
                            
                                
                        *classIdx = 2;
                        *classScore = 202.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 194.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[27] <= 0.0008416740747634321) {
                            
                                
                        *classIdx = 1;
                        *classScore = 194.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 202.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[2] <= 0.5723789036273956) {
                            
                                
                        if (x[37] <= 0.014800310134887695) {
                            
                                
                        *classIdx = 2;
                        *classScore = 202.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 194.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[44] <= 0.38511936366558075) {
                            
                                
                        *classIdx = 2;
                        *classScore = 202.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 194.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #3
                 */
                void tree3(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[119] <= 0.07438418921083212) {
                            
                                
                        *classIdx = 0;
                        *classScore = 202.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[4] <= 0.45375199615955353) {
                            
                                
                        if (x[87] <= 0.0005133117956575006) {
                            
                                
                        *classIdx = 2;
                        *classScore = 210.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[67] <= 0.001247675798367709) {
                            
                                
                        *classIdx = 1;
                        *classScore = 198.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 210.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 198.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #4
                 */
                void tree4(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[26] <= 0.00805883388966322) {
                            
                                
                        *classIdx = 0;
                        *classScore = 195.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[22] <= 0.7330456376075745) {
                            
                                
                        if (x[41] <= 0.33395224809646606) {
                            
                                
                        *classIdx = 2;
                        *classScore = 221.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 194.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 194.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #5
                 */
                void tree5(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[88] <= 0.012252376298420131) {
                            
                                
                        *classIdx = 0;
                        *classScore = 199.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[66] <= 0.01529636699706316) {
                            
                                
                        if (x[25] <= 0.3714953809976578) {
                            
                                
                        if (x[111] <= 35.0) {
                            
                                
                        *classIdx = 2;
                        *classScore = 222.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 199.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 189.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[23] <= 0.43310727179050446) {
                            
                                
                        if (x[0] <= 0.8515167534351349) {
                            
                                
                        if (x[9] <= 0.005827568471431732) {
                            
                                
                        *classIdx = 1;
                        *classScore = 189.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 222.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 189.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[36] <= 0.5) {
                            
                                
                        *classIdx = 2;
                        *classScore = 222.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 189.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #6
                 */
                void tree6(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[68] <= 0.026636344380676746) {
                            
                                
                        *classIdx = 0;
                        *classScore = 196.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[4] <= 0.4735657274723053) {
                            
                                
                        if (x[24] <= 0.6166707873344421) {
                            
                                
                        *classIdx = 2;
                        *classScore = 195.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 219.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[46] <= 0.020981973968446255) {
                            
                                
                        if (x[26] <= 0.00805883388966322) {
                            
                                
                        *classIdx = 0;
                        *classScore = 196.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 219.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 195.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #7
                 */
                void tree7(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[3] <= 0.5646620392799377) {
                            
                                
                        if (x[44] <= 0.38867904245853424) {
                            
                                
                        if (x[85] <= 0.2789333909749985) {
                            
                                
                        *classIdx = 1;
                        *classScore = 216.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[20] <= 0.7379778325557709) {
                            
                                
                        *classIdx = 2;
                        *classScore = 187.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 216.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[2] <= 0.5455029010772705) {
                            
                                
                        *classIdx = 2;
                        *classScore = 187.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[6] <= 0.022596691735088825) {
                            
                                
                        *classIdx = 1;
                        *classScore = 216.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[59] <= 0.19294699281454086) {
                            
                                
                        *classIdx = 1;
                        *classScore = 216.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 187.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 207.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #8
                 */
                void tree8(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[79] <= 0.03620725544169545) {
                            
                                
                        *classIdx = 0;
                        *classScore = 199.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[19] <= 0.27425602078437805) {
                            
                                
                        if (x[22] <= 0.6689272522926331) {
                            
                                
                        *classIdx = 2;
                        *classScore = 205.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[7] <= 0.0014302917697932571) {
                            
                                
                        *classIdx = 1;
                        *classScore = 206.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 205.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[86] <= 0.011830819305032492) {
                            
                                
                        *classIdx = 2;
                        *classScore = 205.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[45] <= 0.10881760343909264) {
                            
                                
                        if (x[28] <= 0.1566431149840355) {
                            
                                
                        *classIdx = 2;
                        *classScore = 205.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 206.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 206.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #9
                 */
                void tree9(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[2] <= 0.9401277303695679) {
                            
                                
                        if (x[23] <= 0.43680641055107117) {
                            
                                
                        *classIdx = 2;
                        *classScore = 189.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 206.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[9] <= 0.035763440653681755) {
                            
                                
                        *classIdx = 0;
                        *classScore = 215.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 206.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #10
                 */
                void tree10(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[19] <= 0.033757069148123264) {
                            
                                
                        *classIdx = 0;
                        *classScore = 224.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[22] <= 0.7330456376075745) {
                            
                                
                        if (x[35] <= 11.0) {
                            
                                
                        if (x[29] <= 0.0036231838166713715) {
                            
                                
                        if (x[36] <= 0.5) {
                            
                                
                        *classIdx = 2;
                        *classScore = 209.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 177.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 209.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[99] <= 0.0670721335336566) {
                            
                                
                        *classIdx = 0;
                        *classScore = 224.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 177.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 177.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #11
                 */
                void tree11(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[5] <= 0.24089421331882477) {
                            
                                
                        if (x[18] <= 3.248844623565674) {
                            
                                
                        *classIdx = 2;
                        *classScore = 236.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 192.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[1] <= 0.5646620392799377) {
                            
                                
                        if (x[23] <= 0.13347718678414822) {
                            
                                
                        *classIdx = 2;
                        *classScore = 236.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 192.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 182.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #12
                 */
                void tree12(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[69] <= 0.0003952933589062013) {
                            
                                
                        *classIdx = 0;
                        *classScore = 175.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[69] <= 0.010790450032800436) {
                            
                                
                        if (x[39] <= 0.24722637981176376) {
                            
                                
                        *classIdx = 1;
                        *classScore = 214.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 221.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[21] <= 0.39734894037246704) {
                            
                                
                        *classIdx = 2;
                        *classScore = 221.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[88] <= 0.06002693064510822) {
                            
                                
                        *classIdx = 2;
                        *classScore = 221.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 214.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #13
                 */
                void tree13(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[114] <= 33.0) {
                            
                                
                        if (x[3] <= 0.2394890934228897) {
                            
                                
                        if (x[25] <= 0.3995315432548523) {
                            
                                
                        *classIdx = 2;
                        *classScore = 189.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 197.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[89] <= 0.0012949872179888189) {
                            
                                
                        if (x[59] <= 0.17515213042497635) {
                            
                                
                        *classIdx = 2;
                        *classScore = 189.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 197.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 197.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 224.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #14
                 */
                void tree14(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[109] <= 0.003663749354018364) {
                            
                                
                        *classIdx = 0;
                        *classScore = 206.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[3] <= 0.26157529652118683) {
                            
                                
                        if (x[5] <= 0.2506391108036041) {
                            
                                
                        *classIdx = 2;
                        *classScore = 198.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 206.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[7] <= 0.0020811015274375677) {
                            
                                
                        if (x[20] <= 0.6020345389842987) {
                            
                                
                        *classIdx = 2;
                        *classScore = 198.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 206.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 198.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #15
                 */
                void tree15(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[4] <= 0.4735657274723053) {
                            
                                
                        if (x[80] <= 0.8007246255874634) {
                            
                                
                        *classIdx = 2;
                        *classScore = 226.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[109] <= 0.03604612313210964) {
                            
                                
                        *classIdx = 2;
                        *classScore = 226.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 192.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[44] <= 0.6406100690364838) {
                            
                                
                        *classIdx = 1;
                        *classScore = 192.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 192.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #16
                 */
                void tree16(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[1] <= 0.5617349743843079) {
                            
                                
                        if (x[21] <= 0.43310727179050446) {
                            
                                
                        if (x[0] <= 0.8515167534351349) {
                            
                                
                        if (x[100] <= 0.5363391637802124) {
                            
                                
                        if (x[108] <= 0.1180117018520832) {
                            
                                
                        *classIdx = 1;
                        *classScore = 192.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 216.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 216.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 192.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 192.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[101] <= 0.33378196507692337) {
                            
                                
                        *classIdx = 1;
                        *classScore = 192.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 202.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #17
                 */
                void tree17(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[108] <= 0.03180570324184373) {
                            
                                
                        *classIdx = 0;
                        *classScore = 196.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[35] <= 1.5) {
                            
                                
                        if (x[5] <= 0.24713674932718277) {
                            
                                
                        *classIdx = 2;
                        *classScore = 198.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[25] <= 0.2933156341314316) {
                            
                                
                        *classIdx = 2;
                        *classScore = 198.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 216.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[19] <= 0.3465425670146942) {
                            
                                
                        if (x[5] <= 0.19919098168611526) {
                            
                                
                        *classIdx = 2;
                        *classScore = 198.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 216.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[48] <= 0.13974929973483086) {
                            
                                
                        *classIdx = 2;
                        *classScore = 198.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 216.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #18
                 */
                void tree18(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[106] <= 0.005548383458517492) {
                            
                                
                        *classIdx = 0;
                        *classScore = 201.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[43] <= 0.29177719354629517) {
                            
                                
                        if (x[24] <= 0.6010542511940002) {
                            
                                
                        *classIdx = 2;
                        *classScore = 215.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 194.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[44] <= 0.39186736941337585) {
                            
                                
                        if (x[72] <= 19.0) {
                            
                                
                        *classIdx = 2;
                        *classScore = 215.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 194.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 194.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #19
                 */
                void tree19(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[1] <= 0.6133581697940826) {
                            
                                
                        if (x[25] <= 0.3786398619413376) {
                            
                                
                        if (x[37] <= 0.9328711032867432) {
                            
                                
                        if (x[59] <= 0.07247611880302429) {
                            
                                
                        *classIdx = 1;
                        *classScore = 195.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 210.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 205.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 195.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 205.0;
                        return;

                            
                        }

                }
            
        


            
};



static RandomForestClassifier forest;


#endif
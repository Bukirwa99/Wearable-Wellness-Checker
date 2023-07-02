#ifndef UUID2658709870368
#define UUID2658709870368

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
                            return "idle";
                    
                        case 1:
                            return "waving";
                    
                        case 2:
                            return "walking";
                    
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
                    
                        if (x[115] <= 29.0) {
                            
                                
                        if (x[39] <= 0.15652862936258316) {
                            
                                
                        *classIdx = 2;
                        *classScore = 122.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 108.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 120.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #1
                 */
                void tree1(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[60] <= 0.539473682641983) {
                            
                                
                        *classIdx = 0;
                        *classScore = 123.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[49] <= 0.00826943339779973) {
                            
                                
                        *classIdx = 2;
                        *classScore = 120.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 107.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #2
                 */
                void tree2(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[46] <= 0.007331744534894824) {
                            
                                
                        *classIdx = 0;
                        *classScore = 117.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[86] <= 0.029935086145997047) {
                            
                                
                        *classIdx = 2;
                        *classScore = 120.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 113.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #3
                 */
                void tree3(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[62] <= 0.5514874160289764) {
                            
                                
                        *classIdx = 0;
                        *classScore = 125.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[21] <= 0.47446809709072113) {
                            
                                
                        *classIdx = 1;
                        *classScore = 116.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 109.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #4
                 */
                void tree4(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[107] <= 0.000784051779191941) {
                            
                                
                        if (x[107] <= 3.5720083644719125e-05) {
                            
                                
                        *classIdx = 0;
                        *classScore = 103.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 117.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 130.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #5
                 */
                void tree5(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[89] <= 0.0003246186468004453) {
                            
                                
                        *classIdx = 0;
                        *classScore = 118.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[45] <= 0.18303793668746948) {
                            
                                
                        *classIdx = 2;
                        *classScore = 117.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 115.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #6
                 */
                void tree6(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[74] <= 34.0) {
                            
                                
                        if (x[9] <= 0.004627861664630473) {
                            
                                
                        *classIdx = 2;
                        *classScore = 115.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 118.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 117.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #7
                 */
                void tree7(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[26] <= 0.007863656152039766) {
                            
                                
                        *classIdx = 0;
                        *classScore = 126.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[6] <= 0.021011770702898502) {
                            
                                
                        *classIdx = 2;
                        *classScore = 112.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 112.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #8
                 */
                void tree8(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[2] <= 0.6991330981254578) {
                            
                                
                        *classIdx = 2;
                        *classScore = 137.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[119] <= 0.05645006545819342) {
                            
                                
                        *classIdx = 0;
                        *classScore = 112.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 101.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #9
                 */
                void tree9(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[7] <= 0.0008471849141642451) {
                            
                                
                        if (x[59] <= 0.05363202281296253) {
                            
                                
                        *classIdx = 0;
                        *classScore = 108.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 119.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 123.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #10
                 */
                void tree10(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[59] <= 0.05851314775645733) {
                            
                                
                        *classIdx = 0;
                        *classScore = 118.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[21] <= 0.47446809709072113) {
                            
                                
                        *classIdx = 1;
                        *classScore = 134.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[107] <= 0.006095082964748144) {
                            
                                
                        *classIdx = 2;
                        *classScore = 98.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 134.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #11
                 */
                void tree11(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[82] <= 0.517734557390213) {
                            
                                
                        *classIdx = 0;
                        *classScore = 117.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[49] <= 0.008209799882024527) {
                            
                                
                        *classIdx = 2;
                        *classScore = 104.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 129.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #12
                 */
                void tree12(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[78] <= 0.5980128049850464) {
                            
                                
                        *classIdx = 0;
                        *classScore = 106.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[25] <= 0.4269779473543167) {
                            
                                
                        *classIdx = 1;
                        *classScore = 119.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 125.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #13
                 */
                void tree13(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[119] <= 0.024806939298287034) {
                            
                                
                        *classIdx = 0;
                        *classScore = 118.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[42] <= 0.5472972989082336) {
                            
                                
                        *classIdx = 2;
                        *classScore = 108.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 124.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #14
                 */
                void tree14(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[119] <= 0.1715960055589676) {
                            
                                
                        if (x[38] <= 1.5167459845542908) {
                            
                                
                        if (x[108] <= 0.02930095579358749) {
                            
                                
                        *classIdx = 0;
                        *classScore = 106.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 128.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 116.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[111] <= 13.5) {
                            
                                
                        *classIdx = 2;
                        *classScore = 116.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 128.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #15
                 */
                void tree15(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[99] <= 0.02785638254135847) {
                            
                                
                        *classIdx = 0;
                        *classScore = 121.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[40] <= 0.5937021970748901) {
                            
                                
                        *classIdx = 2;
                        *classScore = 122.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 107.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #16
                 */
                void tree16(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[44] <= 0.3973482847213745) {
                            
                                
                        *classIdx = 2;
                        *classScore = 122.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[46] <= 0.012930720578879118) {
                            
                                
                        *classIdx = 0;
                        *classScore = 122.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 106.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #17
                 */
                void tree17(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[86] <= 0.029830009676516056) {
                            
                                
                        if (x[0] <= 0.6992605924606323) {
                            
                                
                        *classIdx = 2;
                        *classScore = 115.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[78] <= 1.4560167789459229) {
                            
                                
                        *classIdx = 0;
                        *classScore = 109.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 126.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 126.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #18
                 */
                void tree18(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[70] <= 9.5) {
                            
                                
                        *classIdx = 0;
                        *classScore = 124.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[40] <= 0.5472972989082336) {
                            
                                
                        *classIdx = 2;
                        *classScore = 107.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 119.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #19
                 */
                void tree19(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[79] <= 0.07125529603217728) {
                            
                                
                        *classIdx = 0;
                        *classScore = 119.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[49] <= 0.00924657704308629) {
                            
                                
                        *classIdx = 2;
                        *classScore = 112.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 119.0;
                        return;

                            
                        }

                            
                        }

                }
            
        


            
};



static RandomForestClassifier forest;


#endif
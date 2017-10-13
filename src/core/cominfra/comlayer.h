/*******************************************************************************
  * Copyright (c) 2010-2014 fortiss, TU Wien ACIN and Profactor GmbH.
  * All rights reserved. This program and the accompanying materials
  * are made available under the terms of the Eclipse Public License v1.0
  * which accompanies this distribution, and is available at
  * http://www.eclipse.org/legal/epl-v10.html
  *
  * Contributors:
  *    Alois Zoitl - initial implementation and rework communication infrastructure
  *    Michael Hofmann - rework communication infrastructure
  *    Ingo Hegny - fix doxygen-documentation inconsistencies
  *    Martin Melik-Merkumians - add serial communication layer for ONE input and ONE output
  *******************************************************************************/
#ifndef _COMLAYER_H_
#define _COMLAYER_H_

#include "comtypes.h"

namespace forte {
  namespace com_infra {

    class CBaseCommFB;

    class CComLayer{
      public:
        virtual ~CComLayer();

        /*!\brief Configure the current layer and perform necessary means to setup the connection
         *
         * Depending on the layers functionality different things have to be performed here.
         * This can range from doing nothing to establishing a TCP session.
         *
         * @param pa_acLayerParameter configuration data for this layer
         * @return status of the opening process
         *      - e_InitOk of the opening process was successful
         */
        virtual EComResponse openConnection(char *pa_acLayerParameter) = 0;

        /*!\brief Close this layer
         *
         * Implementations of this function should perform the actions necessary for closing.
         */
        virtual void closeConnection() = 0;

        /*!\brief Take the given data and perform the necessary process for sending
         *
         * If necessary invoke bottom layer sendData functions.
         *
         * @param pa_pvData pointer to the data to be sent
         * @param pa_unSize size of the data to be sent
         * @return status of the sending process:
         *    - e_ProcessDataOk ... if sending process was successful
         */
        virtual EComResponse sendData(void *pa_pvData, unsigned int pa_unSize) = 0;

        /*!\brief Take the given data and perform the necessary process for receiving data
         *
         * This function is called for processing the received data from bottom to top. Therefore
         * if necessary invoke the top layer's receiveData function to hand on the processed data.
         *
         * @param pa_pvData pointer to the data received
         * @param pa_unSize size of the data received
         * @return status of the receiving process depends on if the layer is the bottom most layer:
         *    - Normal Layer:
         *        - e_ProcessDataOk ... if receiving process was successful
         *    - Bottom most layer
         *        - e_Nothing ...  if the processing of the data does not require to send an external event to the FB
         *        - any other value requires that the ComFB is informed with an external event to further handle the received message
         */
        virtual EComResponse recvData(const void *pa_pvData, unsigned int pa_unSize) = 0;

        /*!\brief Finish to process the data received in a context outside the communication interrupt i.e. within the event chain of the ComFB.
         *
         * This function shall be used for finishing the data reception.
         */
        virtual EComResponse processInterrupt();

        /*!\brief get the top layer
         */
        CComLayer *getTopLayer() const {
          return m_poTopLayer;
        }

        /*!\brief get the bottom layer
         */
        CComLayer *getBottomLayer() const {
          return m_poBottomLayer;
        }

        /*!\brief set the bottom layer
         */
        void setBottomLayer(CComLayer *layer) {
          m_poBottomLayer = layer;
        }


        /*!\brief get the FB of this layer
         */
		CBaseCommFB *getCommFB() const {
          return m_poFb;
        }

      protected:
        CComLayer(CComLayer* pa_poUpperLayer, CBaseCommFB* pa_poComFB);

        EComConnectionState m_eConnectionState;

        CComLayer *m_poTopLayer;
        CComLayer *m_poBottomLayer;
		CBaseCommFB *m_poFb;

      private:
    };

  }
}

#endif
